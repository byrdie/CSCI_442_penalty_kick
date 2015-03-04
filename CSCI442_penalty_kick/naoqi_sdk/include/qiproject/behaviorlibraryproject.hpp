/**
 * Copyright (c) 2012 Aldebaran Robotics  All Rights Reserved
 */

#ifndef _QI_PROJECT_BEHAVIOR_LIBRARY_PROJECT_H_
#define _QI_PROJECT_BEHAVIOR_LIBRARY_PROJECT_H_

#include <map>
#include <list>
#include <set>
#include <boost/signal.hpp>
#include <qiproject/project.hpp>

namespace qi
{
  namespace project
  {
    class BehaviorProject;
    class BehaviorLibraryProjectPrivate;

    /**
     * Class for behavior tree management.
     * Note that every std::string in API must be encoded as UTF-8.
     */
    class BehaviorLibraryProject : public qi::project::Project
    {
    public:
      /**
       * Constructor. Will load the behavior library at the given path.
       * @param path the path towards an existing directory.
       */
      BehaviorLibraryProject(const std::string& path = std::string());

      /**
       * Copy constructor.
       * @param path another behavior library object.
       */
      BehaviorLibraryProject(const BehaviorLibraryProject& proj);

      /**
       * Constructor from base class objects.
       */
      BehaviorLibraryProject(const Project& proj);

      /**
       * Assignment operator overload.
       */
      BehaviorLibraryProject& operator=(const BehaviorLibraryProject &rhs);

      /**
       * Destructor.
       */
      virtual ~BehaviorLibraryProject() throw();

      /**
       * Gets the name of the behavior library.
       * @return The ALPath
       */
      std::string name() const;

      /**
       * @brief Sets the name of the behavior library.
       * @param pName the name you like.
       * @return true on success, false otherwise.
       */
      bool setName(const std::string& pName);

      /**
       * @brief Tells whether a behavior is found at the given localPath.
       * @param localPath a path to check from the local root.
       * @return true if present and is a behavior, false otherwise.
       */
      bool hasBehavior(const std::string& localPath) const;

      /**
       * Adds a behavior to the library.
       * Export path must point a valid behavior directory or file.
       * @param remotePath an absolute path towards a behavior project to import.
       * @param localPath a path relative to the library root.
       * @param overwrite whether to replace local behavior.
       */
      bool importBehavior(const std::string& remotePath,
                          const std::string& localPath = std::string(),
                          bool overwrite = false);

      /**
       * Exports a behavior from the library.
       * @param localPath a path relative to the library root.
       * @param remotePath an absolute path towards a behavior project to import.
       * @param overwrite whether to replace remote behavior.
       */
      bool exportBehavior(const std::string& localPath,
                          const std::string& remotePath,
                          qi::project::ArchiveFormat format = qi::project::ArchiveFormat_Default,
                          bool overwrite = false) const;

      /**
       * Remove a behavior from the library.
       * @param localPath a path relative to the library root.
       */
      bool removeBehavior(const std::string& localPath);

      /**
       * @brief List every behavior local paths from the given local root.
       * @param localPath the path towards a local directory.
       * @param recursive whether to look in subdirectories.
       * @return A set of local paths towards valid behaviors.
       */
      std::set<std::string> behaviorPaths(
        const std::string& localPath = std::string(),
        bool recursive = true) const;

      /**
       * @brief List every behaviors found in library under the given root.
       * @param localPath the path towards a local directory.
       * @param recursive whether to look in subdirectories.
       * @return A set of local paths towards valid behaviors.
       */
      std::set<qi::project::BehaviorProject> behaviors(
        const std::string& localPath = std::string(),
        bool recursive = true) const;

      /**
       * @brief Add a tag to a behavior.
       * Tag will be appended to the tag list of the behavior.
       * Returns true when the tag is added, false otherwise.
       * @param localPath local path to the behavior to tag.
       * @param tag the tag to set.
       * @return whether the tag was actually added.
       */
      bool addTag(const std::string& localPath, const std::string& tag);

      /**
       * @brief Set a tag to a behavior.
       * Set tag will be appended to the tag list of the behavior.
       * @param localPath local path to the behavior to tag.
       * @param tag the tag to set.
       * @return whether the tag was actually removed.
       */
      bool removeTag(const std::string& localPath, const std::string& tag);

      /**
       * @brief Find behaviors providing the given tag.
       * Retrieves the list of local paths to the behaviors that provide the tag.
       * @param tag The tag to lookup
       * @return a list of local paths towards valid behaviors.
       */
      std::set<std::string> findTag(const std::string& tag) const;

      /**
       * @brief List every tag found in library's behaviors.
       * @param localPath the path towards a local directory (or a behavior).
       * @param recursive whether to look in subdirectories.
       * @return A set of tags as strings.
       */
      std::set<std::string> tags(
        const std::string& localPath = std::string(),
        bool recursive = true) const;

      /**
       * @brief Scans the library directory for changes in tags or behaviors.
       * When differences are detected between actual behavior library content
       * and indexed content, index is updated and signals are emitted.
       * @param localPath the sub-part of the library to check.
       */
      void update(const std::string& localPath = std::string());

      /// Signal for added behavior event.
      boost::signal<void(const std::string& localPath)> behaviorAdded;

      /// Signal for updated behavior event.
      boost::signal<void(const std::string& localPath)> behaviorUpdated;

      /// Signal for removed behavior event.
      boost::signal<void(const std::string& localPath)> behaviorRemoved;

      /// Signal for tag updated event.
      /// Emitted just after behaviorAdded, just before behaviorRemoved,
      /// after behaviorUpdated if the behavior added the tag and
      /// before behaviorUpdated if the behavior removed the tag.
      boost::signal<void(const std::string& tag)> tagUpdated;

    private:
      /// Private implementation.
      BehaviorLibraryProjectPrivate* _p;

    }; // End of class Behavior Library

    /**
     * Creates a new behavior library at the given path, as a directory.
     * @param path where to create the behavior library.
     * @param name an optional name, takes the filename by default.
     */
    bool makeBehaviorLibraryProject(const std::string& path,
                                    const std::string& pName = std::string());


  } // End of namespace project
} // End of namespace qi

#endif // _QI_PROJECT_BEHAVIOR_LIBRARY_PROJECT_H_
