#include <iostream>
#include "pystring/pystring.h"
int main(int, char**) { 
    std::string s =  "this is string example....wow!!! this is really string";
    std::cout << pystring::replace(s, "is", "was", 3) << std::endl;
    return 0;
}
