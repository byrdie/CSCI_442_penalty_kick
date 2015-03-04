/**
 * @author Victor Paleologue
 * Copyright (c) Aldebaran Robotics 2011 All Rights Reserved
 */

#pragma once

#ifndef _LIBQI_QI_PROJECT_HPP_
#define _LIBQI_QI_PROJECT_HPP_

#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

namespace qi
{
  namespace project
  {
    /// @brief Supported project formats.
    enum ArchiveFormat
    {
      ArchiveFormat_AutoDetect = -2
    , ArchiveFormat_Default = -1
    , ArchiveFormat_Directory = 0
    , ArchiveFormat_TAR
    , ArchiveFormat_ZIP
    , ArchiveFormat_TAR_GZ
    , ArchiveFormat_TAR_BZ2
    , ArchiveFormat_DEB
    };

    /// @brief Thrown by invalid projects on operations requiring validation.
    class InvalidProject : public std::exception
    {
    public:
      InvalidProject() : std::exception() { }
      InvalidProject(const InvalidProject&) : std::exception() { }
      virtual const char* what() const throw()
      { return "invalid project instance"; }
    };

    /// @brief Thrown by methods requiring valid paths arguments.
    class PathNotFound : public std::runtime_error
    {
    public:
      PathNotFound(const std::string& path) : std::runtime_error(path) { }
      PathNotFound(const PathNotFound& other) : std::runtime_error(other.what()) { }
    };

    /// @brief Thrown when a project format does not match or could not be recognized
    class UnsupportedFormat : public std::exception
    {
    public:
      UnsupportedFormat(
        const std::string& triedPath
      , const ArchiveFormat& triedFormat)
      : std::exception()
      , path(triedPath)
      , format(triedFormat)
      { }
      UnsupportedFormat(
        const UnsupportedFormat& other)
      : std::exception()
      , path(other.path)
      , format(other.format)
      { }

      ~UnsupportedFormat() throw() { }

      const std::string path;
      const ArchiveFormat format;

      virtual const char* what() const throw()
      {
        std::stringstream message;
        message << path << ": " << format;
        return message.str().c_str();
      }
    };

    /// @brief Thrown when the project content does not match the format.
    class CorruptedFile : public std::runtime_error { };

    /// @brief Thrown upon I/O access failure.
    class IOError : public std::runtime_error
    {
    public:
      IOError(const std::string& path) : runtime_error(path) { }
      IOError(const IOError& other) : runtime_error(other.what()) { }
    };

    /// @brief Thrown upon I/O read access failure.
    class IOReadError : public IOError
    {
    public:
      IOReadError(const std::string& path) : IOError(path) { }
      IOReadError(const IOReadError& other) : IOError(other) { }
    };

    /// @brief Thrown upon I/O write access failure.
    class IOWriteError : public IOError
    {
    public:
      IOWriteError(const std::string& path) : IOError(path) { }
      IOWriteError(const IOWriteError& other) : IOError(other) { }
    };

    /// @brief Thrown upon content creation where content already exists.
    class AlreadyExists : public std::runtime_error
    {
    public:
      AlreadyExists(const std::string& path) : runtime_error(path) { }
      AlreadyExists(const AlreadyExists& other) : runtime_error(other.what()) { }
    };

    // Forward declaration for implementation
    class ProjectImpl;

    /**
     * @brief Object representing a project directory.
     * @warning using QString with this header included on a Linux, please note
     * that default file name encodings are set to UTF-8.
     */
    class Project
    {
    public:
      /**
       * @brief Represents the project directory found at the given path.
       * Throws if the path is not found or is not readable.
       * @param projectDir the absolute path towards the project directory.
       */
      Project(const std::string& projectDir = std::string()) throw();

      /**
       * @brief Copy Constructor.
       */
      Project(const Project& other) throw();

      /**
       * @brief Destroy the project instance.
       * Does not alter filesystem.
       */
      virtual ~Project() throw();

      /**
       * @brief Assignment operation.
       */
      Project& operator =(const Project& other) throw();

      /**
       * @brief Comparison operator.
       */
      bool operator <(const Project& other) const;

      /**
       * @brief Comparison operator.
       */
      bool operator >(const Project& other) const;

      /**
       * @brief Comparison operator.
       */
      bool operator ==(const Project& other) const;


      /**
       * @brief Swap (effective c++ recommendation)
       */
      inline void swap(Project& other) { std::swap(fImpl, other.fImpl); }

      /**
       * @brief The path tracked by this project instance.
       */
      virtual std::string projectPath() const throw();

      /**
       * @brief Check whether the tracked project directory still exists.
       * An "inexistant" project instance behavior is undefined.
       * Instance methods should throw InvalidInstance exception.
       * @return true if the project directory exists, false otherwise.
       */
      bool valid() const throw();

      /**
       * @brief Get all the project's metadata.
       * Metadata are named non-empty strings. It uses the HTTP header syntax,
       * but is case-sensitive.
       * @return a map containing all the metadata.
       */
      std::map<std::string, std::string> getMetadata() const throw();

      /**
       * @brief Get a single metadata value.
       * @param key the name of the metada to request.
       * @return the value of the metadata or an empty string if key not found.
       */
      std::string getMetadata(const std::string& key) const throw();

      /**
       * @brief Set all the project's metadata.
       * All previous metadata will be cleared and replaced.
       * @param metadata a map containing every metadata.
       * @throw IOWriteError whenever we cannot write metadata.
       */
      void setMetadata(
        const std::map<std::string, std::string>& metadata
      );

      /**
       * @brief Set a single metadata value.
       * Will not alter other metadata keys.
       * @param key the metadata name to set.
       * @param value the new value to set.
       * @throw IOWriteError whenever we cannot write metadata.
       */
      void setMetadata(
        const std::string& key
      , const std::string& value
      );

    private:
      /**
       * @brief Private implementation holder.
       */
      ProjectImpl* fImpl;


    }; // End of class Project

    /**
     * @brief Creates an empty project directory at the given path.
     * Fails if path exists and is not an empty directory, or if parent path
     * does not exist.
     * @param absolutePath an absolute path where to make the project.
     * @return true on success, false otherwise.
     */
    bool makeProject(const std::string& absolutePath);

    /**
     * Creates a project directory out of a project archive or directory.
     * @param sourcePath the path to the source project to import.
     * @param destDir the path to the new project directory.
     * @param format the format of the project to import.
     * @throw PathNotFound, IOError, UnsupportedFormat, CorruptedFile
     */
    void importProject(
      const std::string& sourcePath
    , const std::string& destPath
    , const ArchiveFormat& format = ArchiveFormat_AutoDetect
    );

    /**
     * Exports a project directory to a project archive or directory.
     * @param sourceProject the path towards the original project.
     * @param destPath the path towards the project export result.
     * @param format the exportation format.
     * @throw PathNotFound, AlreadyExists, IOError
     */
    void exportProject(
      const std::string& sourceProject
    , const std::string& destPath
    , const ArchiveFormat& format
    );

    /**
     * Detect the project format at the given path.
     * @param projectPath the path towards the project to analyse.
     * @throw PathNotFound or UnsupportedFormat if unrecognized, or IOReadError
     */
    ArchiveFormat detectFormat(
      const std::string& projectPath
    );

    /**
     * @brief Parse metadata from string.
     * @param dataStr a data string to parse.
     * @return a metadata map.
     */
    std::map<std::string, std::string> unserializeMetadata(
      const std::string& dataStr
    ) throw();

    /**
     * @brief Serialize metadata to string.
     * @param metadata a metadata map to serialize.
     * @return a string representing metadata in a parsable format.
     */
    std::string serializeMetadata(
      const std::map<std::string, std::string>& metadata
    ) throw();

  } // End of namespace project
} // End of namespace qi

namespace std
{
  /// @brief Custom swap implementation.
  template<>
  void swap<qi::project::Project>(qi::project::Project &a,
                                  qi::project::Project &b);
} // End of namespace std

#endif // _LIBQI_QI_PROJECT_HPP_
