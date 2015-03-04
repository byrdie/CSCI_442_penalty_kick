/**
 * @author Guillaume Schweitzer
 * Copyright (c) Aldebaran Robotics 2012 All Rights Reserved
 */

#pragma once

#ifndef _LIB_QIPROJECT_QIPROJECTUTILS_HPP_
#define _LIB_QIPROJECT_QIPROJECTUTILS_HPP_

#include <qiproject/project.hpp>
#include <QString>

namespace qi
{
  namespace project
  {
    /**
     * Remove a file or a directory.
     * @param toRemove the file or directory to remove.
     * @throw PathNotFound
     */
    void remove(const QString& toRemove);

    /**
     * Copy a file or a directory.
     * @param fromPath the file or directory to copy. Must exist.
     * @param toPath the destination where to copy to.
     * @param overwrite if false, throw if destination exists and is not empty.
     * @throw PathNotFound, AlreadyExists, std::runtime_error
     */
    void copy(const QString& fromPath
    , const QString& toPath
    , const bool& overwrite = false
    );

    /**
     * Move (rename) a file or a directory.
     * May take a long time when from a partition to another.
     * @param fromPath the file or directory to move. Must exist.
     * @param toPath the destination where to move to.
     * @param overwrite if false, throw if destination exists and is not empty.
     * @throw PathNotFound, AlreadyExists, std::runtime_error
     */
    void move(const QString& fromPath
    , const QString& toPath
    , const bool& overwrite = false
    );

    /**
     * List all currently present files in given directory.
     * @param root the relative path of a directory to list.
     * @param showHidden whether to include hidden files in listing.
     * @param recursive whether to list subdirectories too.
     * @param includeDirectories whether to include directories in list.
     * @return a list of paths, relative to the given subpath, empty on failure.
     */
    QStringList listDirectory(const QString& dirPath, bool showHidden,
                              bool recursive, bool includeDirectories);

  } // End of namespace project
} // End of namespace qi

#endif // _LIB_QIPROJECT_QIPROJECTUTILS_HPP_
