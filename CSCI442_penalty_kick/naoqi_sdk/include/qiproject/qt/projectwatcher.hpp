/**
 * @author Victor Paleologue
 * Copyright (c) Aldebaran Robotics 2011-2012 All Rights Reserved
 */

#pragma once

#ifndef _LIB_QIPROJECT_QI_QIPROJECTWATCHER_HPP_
#define _LIB_QIPROJECT_QI_QIPROJECTWATCHER_HPP_

#include <QDir>
#include <QSet>
#include <QMap>
#include <qiproject/project.hpp>

class QTimer;
class QMutex;

namespace qi
{
  namespace project
  {
    /**
     * Types of events that can be signalled.
     */
    enum FileSystemEvent
    {
      FileAdded
    , FileRemoved
    , FileChanged
    };

    class ProjectWatcher
    : public QObject
    , public QDir
    , public Project
    {
      Q_OBJECT

    public:
      /**
       * @brief Represents the project found at the given path.
       * Throws if the path is not found or is not readable.
       * @param projectPath the absolute path towards the project listened.
       */
      ProjectWatcher(
        const QString& projectPath,
        QObject* parent = 0
      );

      /**
       * @brief Represents the project found at the given path.
       * Throws if the path is not found or is not readable.
       * @param projectPath the absolute path towards the project listened.
       */
      ProjectWatcher(
        const Project& project,
        QObject* parent = 0
      );

      /**
       * @brief Destroy the project instance.
       * Does not alter filesystem.
       */
      virtual ~ProjectWatcher() throw();

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

    Q_SIGNALS:
      /**
       * A signal describing an atomic event on filesystem.
       */
      void contentChanged(const QString&, qi::project::FileSystemEvent);
      void contentChanged(const QMap<QString, qi::project::FileSystemEvent>& changes);

    private Q_SLOTS:
      /// Slot for catching QTimer signal.
      void onTimeout();

    private:
      /**
       * @brief List all subpaths found for the given path.
       * Returns a list of all paths (directories and files) present
       * inside 'from' path, which can be a relative path to the
       * project watcher, or an absolute path.
       * @param from a relative or absolute path to list.
       */
      QStringList xListAllPaths(const QString& from = QString());

      /// A timer which gives the tick for every filesystem check.
      QTimer* fTimer;

      /// A mutex to synchronize file content checks.
      QMutex* fMutex;

      /// The directory content found at last check.
      QSet<QString> fDirectoryContent;

      /// Details of the file last modification dates of the directory content.
      QMap<QString, QDateTime> fFilesLastModified;

      /// Details of the file sizes of the directory content.
      QMap<QString, size_t> fFilesSize;

      // Disabling few methods that are not allowed for ALProject coherence
      /// Disabled.
      QString setPath();

      /// Disabled.
      bool cd(const QString &dirName);

      /// Disabled.
      bool cdUp();

    }; // End of class ProjectWatcher
  } // End of namespace project
} // End of namespace qi
#endif // _LIB_QIPROJECT_QI_QIPROJECTWATCHER_HPP_
