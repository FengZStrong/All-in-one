#include <iostream>
#include <vector>

using it_num = std::vector<int>::iterator;

bool find_num(it_num begin, it_num end, const int &num)
{
	while (begin != end)
	{
		if(*begin == num)
		{
			return true;
		}
		++begin;
	}

	return false;
}

int find_num_return_int(it_num begin, it_num end, const int &num)
{
	while (begin != end)
	{
		if(*begin == num)
		{
			return *begin;
		}
		++begin;
	}

	return 0;
}

int main()
{
	std::vector<int> vec{1,2,3,4,5,6,7,8,9};
	if(find_num(vec.begin(), vec.end(), 10))
	{
		std::cout << "Find\n";
	}

	std::cout << find_num_return_int(vec.begin(), vec.end(), 2) << std::endl;
}