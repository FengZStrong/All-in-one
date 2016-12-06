#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
	//using iter = std::list<char *>::iterator;
	std::list<char *> l = {"a", "b", "c"};
	std::vector<std::string> vec;
	vec.assign(l.begin(), l.end());
	for (const std::string &s : vec)
	{
		std::cout << "vec: " << s << std::endl;
	}
}