#ifndef INCLUDE_PYSTRING_H
#define INCLUDE_PYSTRING_H

#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>

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
    /// substr: The substring to search for
    /// start: The start index of the string
    /// end: The end index of the string
    /// 
    int count(const std::string & str, const std::string & substr, int start = 0, int end = -1);

    /////////////////////////////////////////////////
    /// brief: This function determines whether the string ends with the specified suffix. 
    /// It returns True if it ends with the specified suffix, False otherwise. 
    /// The optional arguments "start" and "end" are the start and end positions of the retrieval string.
    /// suffix: This parameter can be a string or an element
    /// start: The beginning position in the string
    /// end: End position in character
    /// 
    bool endswith(const std::string &str, const std::string &suffix, int start = 0, int end = -1);

    /////////////////////////////////////////////////
    /// @brief: Return a copy of the string with all tab characters are expanded using spaces.
    /// if tabsize is not given, a tab size of 8 characters is assumed.
    std::string expandtabs(const std::string &str, int tabsize = 8);
    
    /////////////////////////////////////////////////
    /// @brief: Return the lowest index in the string where substring sub is found within the slice s[start:end].
    /// Optional arguments start and end are interpreted as in slice notation.
    /// Return -1 if sub is not found.
    /// 
    int find(const std::string &str, const std::string &sub, int start = 0, int end = -1);
    
    /////////////////////////////////////////////////
    /// @brief:Checks to see if the string contains the substring str, 
    /// and if beg (start) and end (end) ranges are specified, 
    /// the same as python's find() method, except that an exception is raised 
    /// if str is not in string.
    int index(const std::string &str, const std::string &sub, int start = 0, int end = -1);
    
    ////////////////////////////////////////////////
    /// @brief: This function detects whether a string consists of letters and strings
    ///
    bool isalnum(const std::string &str);
    
    ////////////////////////////////////////////////
    /// @brief: This function detects whether a string consists of only letters.
    /// 
    bool isalpha(const std::string &str);
    
    ///////////////////////////////////////////////
    /// @brief: This function detects whether a string consists only of numbers 
    /// and is valid only for 0 and positive numbers.
    /// 
    bool isdigit(const std::string &str);
    
    ///////////////////////////////////////////////
    /// @brief: This function detects whether the string consists of lowercase letters
    ///
    bool islower(const std::string &str);
    
    ///////////////////////////////////////////////
    /// @brief: This function detects whether the string consists of whitespaces
    ///
    bool isspace(const std::string &str);

    //////////////////////////////////////////////
    /// @brief: This function detects whether the string consists of uppercase letters
    ///
    bool isupper(const std::string &str);
    
    ///////////////////////////////////////////////
    /// @brief: This function detects whether all words in the string start with a
    /// capital letter and all other letters are lowercase.
    /// 
    bool istitle(const std::string &str);
    
    ///////////////////////////////////////////////
    /// @brief: This function is used to concatenate the elements in a sequence
    /// with the specified string to produce a new string
    ///
    std::string join(const std::string &str, const std::vector<std::string> &seq);
    
}


#endif