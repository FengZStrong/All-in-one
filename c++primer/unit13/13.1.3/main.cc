#include "HasPtr.h"

void test(const HasPtr *pHs, HasPtr hp)
{
	HasPtr hp1(*pHs), hp2(hp);
}

int main()
{
	HasPtr *pHs = new HasPtr("test");
	test(pHs, HasPtr("test2"));
	std:: cout << "func test end" << std::endl;

	delete pHs;
	std:: cout << "delete pHs end" << std::endl;

	HasPtr test1(std::string("test1"));
	HasPtr test2;
	test2 = test1;
}