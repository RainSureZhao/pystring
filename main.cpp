#include <iostream>
#include "pystring/pystring.h"
int main(int, char**) { 
    std::string s = "runoob\t12345\tabc";
    std::cout << pystring::expandtabs(s, 3) << std::endl;
}
