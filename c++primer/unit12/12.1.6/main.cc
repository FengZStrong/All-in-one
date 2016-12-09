#include <iostream>
#include "StrBlob.h"

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = {"a", "b", "c"};
		b1 = b2;
		b2.push_back("d");
	}
	std::cout << b1.size() << std::endl;

	const StrBlob cb = {"1", "2", "3"};
	std::cout << "front: " << cb.front() << ", size: " << cb.size() << std::endl;
}