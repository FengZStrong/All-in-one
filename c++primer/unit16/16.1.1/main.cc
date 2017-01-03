#include "compare.h"
#include <iostream>
#include <string>

int main()
{
    std::string str1("a");
    std::string str2("b");
    std::cout << compare<std::string>(str1, str2) << std::endl;

    std::cout << compare<int>(1, 1) << std::endl;

    std::cout << compare(100, 1) << std::endl;
}