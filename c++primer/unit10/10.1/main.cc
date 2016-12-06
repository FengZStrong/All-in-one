#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::vector<int> vec = {1,2,3,4,5,6,72,2,2,2,2,2};
	std::cout << "count: " << count(vec.begin(), vec.end(), 2) << std::endl;

	std::list<std::string> l = {"a", "b", "c", "a", "b", "c", "a", "b", "c"};
	std::cout << "count: " << count(l.begin(), l.end(), "a") << std::endl;
}
