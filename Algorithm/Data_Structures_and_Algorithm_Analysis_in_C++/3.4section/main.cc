#include "Vector.h"
#include <iostream>
#include <string>

int main()
{
	Vector<std::string> v(0);

	for (int i = 0; i < 10; ++i)
	{
		std::string s("hello world");
		v.push_back(s);
	}

	Vector<std::string>::iterator iter = v.begin();
	for (; iter != v.end(); ++iter)
		std::cout << *iter << std::endl;
}