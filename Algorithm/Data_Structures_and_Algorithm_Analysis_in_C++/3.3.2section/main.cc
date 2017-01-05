#include <iostream>
#include <vector>
#include <list>
#include "remove_elems.h"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 400000; ++i)
		vec.push_back(i);
	
	std::cout << "vec.size: " << vec.size() << std::endl;

	std::list<int> lst;
	for (int i = 0; i < 400000; ++i)
		lst.push_back(i);

	std::cout << "lst.size: " << vec.size() << std::endl;

	removeElems(vec);
	std::cout << "vec.size: " << vec.size() << std::endl;
	removeElems(lst);
	std::cout << "lst.size: " << vec.size() << std::endl;
}