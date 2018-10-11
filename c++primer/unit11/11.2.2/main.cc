#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <set>

#include "sales.h"

typedef bool (*fuck)(const Sales_data &, const Sales_data &);

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {

	return lhs.isbn() < rhs.isbn();
}

int main()
{
	std::vector<int> vec = {1,2,3};
	auto v_iter = vec.begin();
	std::map<std::vector<int>::iterator, int> vm = {{v_iter, *v_iter}};

	std::list<int> l = {4,5,6};
	auto l_iter = l.begin();
	//std::map<std::list<int>::iterator, int> lm = {{l_iter, *l_iter}};

	for(const auto &m : vm)
	{
		std::cout << m.second << std::endl;
	}

	std::map<int, int> m;
	m[0];
	std::cout << "size: " << m.size() << std::endl; 


	std::set<Sales_data, fuck> bookstore(compareIsbn);
	std::set<Sales_data, decltype(compareIsbn)*> bookstore1(compareIsbn);
}
