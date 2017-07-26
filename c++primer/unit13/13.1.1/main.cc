#include "HasPtr.h"

int main()
{
	std::string hw("hello world");
	HasPtr *h = new HasPtr(hw);
	HasPtr h1(*h);
    delete h;
	std::cout << *(h1.ps) << std::endl;
	//delete h1.ps;

	std::string *s = new std::string("fuck");
	std::string s1(*s);
	delete s;
	std::cout << s1 << std::endl;
}
