#ifndef INCLUDE_PYSTRING_H
#define INCLUDE_PYSTRING_H

#include <string>
#include <vector>

namespace pystring{
    ///////////////////////////////////////////////////
    /// @brief: Change the first letter of the string to uppercase 
    /// and the other letters to lowercase
    ///
    std::string capitalize(const std::string &str);

    //////////////////////////////////////////////////
    /// @brief:Returns a new string centered in the original string and padded with Spaces up to length width. 
    /// The default padding character is space.
    ///
    std::string center(const std::string &str, size_t width, char fillchar = ' ');

    /////////////////////////////////////////////////
    /// @brief: Return the number of substring occerences in the string s[begin, end]
    /// Optional arguments are at the beginning and end of the string search
    ///
    int count(const std::string & str, const std::string & substr, int start = 0, int end = -1);

}


#endif