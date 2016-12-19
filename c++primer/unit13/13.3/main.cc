#include <vector>
#include <algorithm>
#include "HasPtr.h"

int main()
{
    std::string s1("hello world");
    HasPtr hp1(s1);

    std::string s2("hehe");
    HasPtr hp2(s2);

    //hp2 = hp1;
    //std::cout << *hp2.ps << std::endl;

    swap(hp1, hp2);
    std::cout << *hp1.ps << std::endl;

    std::vector<HasPtr> vec{s1, s2};
    std::sort(vec.begin(), vec.end());
}