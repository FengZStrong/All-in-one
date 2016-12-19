#include "HasPtr.h"

int main()
{
	std::string hw("hello world");
	HasPtr h(hw);
	HasPtr h1 = h;
	std::cout << *h1.ps << std::endl;
	delete h1.ps;
}