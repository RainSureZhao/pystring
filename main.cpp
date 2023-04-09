#include <iostream>
#include "pystring/pystring.h"
int main(int, char**) { 
    std::string s = "abcabc";
    std::string t = "g";
    std::cout << pystring::index(s, t) << "\n";
    return 0;
}
