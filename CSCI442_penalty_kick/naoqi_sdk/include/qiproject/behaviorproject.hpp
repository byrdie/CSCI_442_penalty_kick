/**
 * Copyright (c) 2012 Aldebaran Robotics  All Rights Reserved
 */

#ifndef _QI_PROJECT_BEHAVIOR_PROJECT_H_
#define _QI_PROJECT_BEHAVIOR_PROJECT_H_

#include <set>
#include <qiproject/project.hpp>

namespace qi
{
  namespace project
  {
    /**
     * Class for behavior project management.
     * Note that every std::string in API must be encoded as UTF-8.
     */
    class BehaviorProject : public qi::project::Project
    {
    public:
      /**
       * Constructor. Will load the behavior library at the given path.
       * @param path the path towards an existing directory.
       */
      BehaviorProject(const std::string& path = std::string());

      /**
       * Copy constructor.
       * @param path another behavior library object.
       */
      BehaviorProject(const BehaviorProject& proj);

      /**
       * Constructor from base class objects.
       */
      BehaviorProject(const Project& proj);

      /**
       * Assignment operator overload.
       */
      BehaviorProject& operator=(const BehaviorProject &rhs);

      /**
       * Destructor.
       */
      virtual ~BehaviorProject() throw();

      /**
       * Gets the name of the behavior.
       * @return the current name found in metadata.
       */
      std::string name() const;

      /**
       * Sets the name of the behavior.
       * @param pName the name to be given.
       */
      void setName(const std::string& pName);

      /**
       * @brief List every tag found in library's behaviors.
       * @param localPath the path towards a local directory (or a behavior).
       * @param recursive whether to look in subdirectories.
       * @return A set of tags as strings.
       */
      std::set<std::string> tags() const;

      /**
       * @brief Check for a tag on the behavior.
       * @param tag the tag to check.
       */
      bool hasTag(const std::string& tag) const;

      /**
       * @brief Set a tag to a behavior.
       * Set tag will be appended to the tag list of the behavior.
       * @param tag the tag to set.
       * @return true if tag is added or already present, false otherwise.
       */
      bool addTag(const std::string& tag);

      /**
       * @brief Set a tag to a behavior.
       * Set tag will be appended to the tag list of the behavior.
       * @param tag the tag to set.
       * @return true if tag is removed or already absent, false otherwise.
       */
      bool removeTag(const std::string& tag);
    }; // End of class BehaviorProject

    /**
     * @brief makes a standard empty behavior project.
     * Creates a behavior project directory at the given absolute path.
     * Fails if path exists and is not an empty directory, or if parent path
     * does not exist.
     * @param absolutePath an absolute path where to make the project.
     * @return true on success, false otherwise.
     */
    bool makeBehaviorProject(const std::string& absolutePath);

    /**
     * @brief tell whether the file or directory at the given path is a behavior.
     */
    bool isBehavior(const std::string& absolutePath);

    /**
     * @brief tell whether the file or directory at the given path is a behavior.
     */
    bool isBehavior(const qi::project::Project& project);

  } // End of namespace project
} // End of namespace qi

#endif // _QI_PROJECT_BEHAVIOR_PROJECT_H_
