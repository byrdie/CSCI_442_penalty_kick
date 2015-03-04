/**
 * @author Victor Paleologue
 * @author Guillaume Schweitzer
 * Copyright (c) Aldebaran Robotics 2011-2012 All Rights Reserved
 */

#pragma once

#ifndef _QI_PROJECT_MODEL_HPP_
#define _QI_PROJECT_MODEL_HPP_

#include <QObject>
#include <QMutex>
#include <QMap>

#include <qiproject/qt/projectwatcher.hpp>

namespace AL
{
  class ALProject;
}

namespace qi
{
  namespace project
  {
    class NotSaved : public std::exception
    {
    public:
      virtual const char* what() const throw() { return "Project has unsaved changes."; }
    };

    class ProjectModel : public QObject
    {
      Q_OBJECT

      // For ALProject to QiProjectModel conversions
      friend class AL::ALProject;

    public:
      /**
       * Instantiate a project manager holding a new project.
       */
      ProjectModel(QObject* parent = 0) throw();

      /**
       * Copy constructor.
       */
      ProjectModel(const ProjectModel& other);

      /**
       * Destruction of the project manager.
       * Will destroy any cached project being worked.
       */
      ~ProjectModel() throw();

      /**
       * @brief Assignment operation.
       */
      ProjectModel& operator =(const ProjectModel& other) throw();

      /**
       * @brief Enable project watching.
       * When project watching is enabled, you get "contentChanged" signal
       * emitted when filesystem events are detected.
       * @param enable whether to enable project watching.
       */
      void enableWatching(bool enable);

      /**
       * @brief Tells whether watching is enabled.
       * @return true if watching, else false.
       */
      bool isWatching();

    protected:
      void xReset();
      void xResetProject(ProjectWatcher* project);
      void xInitProject(ProjectWatcher* project);
      ArchiveFormat xGetSourceFormat();

    public:
      /**
       * Create a new cached project with no source path.
       * @throw NotSaved
       */
      void createNew();

      /**
       * Load project located at path projectPath.
       * @param projectPath the path towards the project to load.
       * @param format the format of the project to import.
       * @throw CorruptedFile, PathNotFound, UnsupportedFormat, NotSaved
       */
      void load(const QString & projectPath
        , ArchiveFormat format = ArchiveFormat_AutoDetect
      );

      /**
       * Save current project to projectPath.
       * @param projectPath the path towards the project is saved.
       * @param format the format of the project to export.
       * @throw IOWriteError, PathNotFound, UnsupportedFormat, InvalidProject
       */
      void save(const QString & projectPath = QString()
        , ArchiveFormat format = ArchiveFormat_Default
        , bool overwrite = true
      );

      /**
       * Check whether the project was saved.
       * A saved project cached and source content match.
       * @return false if a difference was detected.
       */
      bool isSaved() const;

    private:
      /**
       * Setter for saved status.
       * Use that, so that signals are emitted automatically.
       */
      void xSetSaved(bool saved);

    public:
      /**
       * Check file existence at given relative path.
       * @return true if file exists.
       */
      bool hasFile(const QString& relativePath) const throw();

      /**
       * Check path existence.
       * @return true if path exists.
       */
      bool hasPath(const QString& relativePath) const throw();

      /**
       * List all currently present files in cached project.
       * @param root the relative path of a directory to list.
       * @param showHidden whether to include hidden files in listing.
       * @param recursive whether to list subdirectories too.
       * @param directories whether to include directories in list.
       * @return a list of paths, relative to the given subpath, empty if fails.
       */
      QStringList getFileList(
        const QString& root = QString()
      , bool showHidden = false
      , bool recursive = true
      , bool directories = false);

      /**
       * Write the given content to the relative path.
       * Automatically creates the necessary directories.
       * Does not actually changes the file at source path until saved.
       * @param relativePath the path to destination file.
       * @param content the data to write.
       * @throw IOWriteError
       */
      void writeFile(
          const QString & relativePath
        , const QByteArray& content);

      /**
       * Get content of the file located at relativePath.
       * @param relativePath the path to source file.
       * @return the read data.
       * @throw PathNotFound, IOReadError
       */
      QByteArray readFile(const QString & relativePath) const;

      /**
       * Get the size of the file within the project.
       * @return the size of the file.
       * @throw PathNotFound
       */
      size_t fileSize(const QString & relativePath) const;

      /**
       * C-like file opening, for performance needs.
       * @param relativePath the relative path from the project root.
       * @return a pointer to a FILE object, null on error.
       */
      FILE* fopen(const QString& relativePath, const QString& mode);

      /**
       * Return all the metadata for the current project.
       * @return a map of the key / value pairs.
       */
      QMap<QString, QString> getMetadata() const throw();

      /**
       * Return a single metadata entry.
       * @return a string, empty if entry not found.
       */
      QString getMetadata(const QString& name) const;

      /**
       * Set a single metadata entry.
       * @param name the key where to store the value.
       * @param value the string value to be stored.
       */
      void setMetadata(const QString& name, const QString& value);

      /**
       * @brief Get the path to the saved project, if any.
       * @return A valid path towards the saved project, empty otherwise.
       */
      const QString& getSourcePath() const;

      /// @brief still used by few widgets. DEPRECATED.
      const QString getFileLocalPath(const QString& sourceRelativePath) const;

      /**
       * @brief Make a directory at the given subpath.
       * @param relativePath the relative path towards the new directory.
       * @param makeParents whether to make absent parent directories.
       * @throw PathNotFound, IOWriteError
       */
      void mkdir(const QString& relativePath, bool makeParents = false);

      /**
       * @brief copy the relative source path 'from' of cached project
       * to the relative destination path 'to' of the same cached project.
       * @param from the relative source path
       * @param to the relative destination path
       * @param overwrite the replace destination path content if it already exists
       * @throw AlreadyExists, PathNotFound, IOError
       */
      void copy(const QString& from, const QString& to, bool overwrite = false);

      /**
       * @brief move the relative source path 'from' of cached project
       * to the relative destination path 'to' of the same cached project.
       * @param from the relative source path
       * @param to the relative destination path
       * @param overwrite the replace destination path content if it already exists
       * @throw AlreadyExists, PathNotFound, IOError
       */
      void move(const QString& from, const QString& to, bool overwrite = false);

      /**
       * @Brief remove the relative source path 'from' of cached project.
       * @param from the relative source path
       * @param to the relative destination path
       * @param overwrite the replace destination path content if it already exists
       * @throw PathNotFound, IOError
       */
      void remove(const QString& from);

      /**
       * Export a file or directory from the project to the filesystem.
       * @param sourceRelativePath the local path of the file to export.
       * @param destAbsolutePath a path on the filesystem.
       * @param overwrite whether to overwrite, will throw on failure.
       * @throw PathNotFound, AlreadyExists, std::runtime_error
       */
      void exportFile(
          const QString& sourceRelativePath
        , const QString& destAbsolutePath
        , bool overwrite = false
      ) const;

      /**
       * Import a file or directory to the project from the filesystem.
       * @param sourceAbsolutePath a path on the filesystem.
       * @param destRelativePath the local path where to import the file.
       * @param overwrite whether to overwrite, will throw on failure.
       * @throw PathNotFound, AlreadyExists, std::runtime_error
       */
      void importFile(
          const QString& sourceAbsolutePath
        , const QString& destRelativePath
        , bool overwrite = false
      );

      /**
       * Import a file or directory to the project from another project.
       * @param sourceProject a valid project from which to get the file.
       * @param sourceRelativePath a relative path from the project root.
       * @param destRelativePath the local path where to import the file.
       * @param overwrite whether to overwrite, will throw on failure.
       * @throw PathNotFound, AlreadyExists, std::runtime_error
       */
      void importFile(
          const ProjectModel& sourceProject
        , const QString& sourceRelativePath
        , const QString& destRelativePath
        , bool overwrite = false
      );

      /**
       * Import a file or directory to the project from the source project.
       * @param relativePath a path relative to the project root.
       * @param overwrite whether to overwrite, will throw on failure.
       * @throw PathNotFound, AlreadyExists, IOError
       */
      void importFromSource(
          const QString& relativePath
        , bool overwrite = false
      );

    Q_SIGNALS:
      /**
       * Signal for live update of saved property.
       */
      void saved(bool saved);

      /**
       * Relays filesystem signals caught from the source project.
       * @param eventList a list of last events caught by the project watcher.
       */
      void sourceProjectEvent(const QMap<QString, qi::project::FileSystemEvent>& eventList);

    private Q_SLOTS:
      /**
       * Catch the source project watcher signal for filesystem events.
       * @param eventList the list of events to process.
       */
      void onSourceContentChanged(const QMap<QString, qi::project::FileSystemEvent>& eventList);

    protected:
      /// The path toward the source file, i.e. the default save location.
      QString fSourcePath;

      /// A project watcher towards the source.
      ProjectWatcher* fSourceProject;

      /// A the cache of the opened project in a temp path.
      ProjectWatcher* fCachedProject;

      /// A mutex for accessing the cached project.
      mutable QMutex fCachedProjectMutex;

      /// The currently selected source (i.e. save) file format.
      ArchiveFormat fSourceFormat;

      /// Whether to watch the source project.
      bool fWatching;

      /// Whether the cached project is synchronized with the source.
      bool fSaved;

    }; // End of class ProjectModel
  } // End of namespace project
} // End of namespace qi

#endif // _QI_PROJECT_MODEL_HPP_
