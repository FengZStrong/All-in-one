#include <iostream>
#include <string>

class fuck
{
public:
	int a;
	std::string s;
	fuck() : a(100) {
		std::cout << a << std::endl;
		a = 101;
	}
};

class test
{
public:
	fuck f;
	test() {}
};