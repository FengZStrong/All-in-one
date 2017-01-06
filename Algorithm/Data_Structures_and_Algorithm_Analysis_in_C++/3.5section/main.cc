#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List<int> lst;
	for (int i = 0; i < 10; ++i)
		lst.push_back(i);
	
	cout << "size: " << lst.size() << endl;

	List<int>::iterator itr = lst.begin();
	for (; itr != lst.end(); ++itr)
	{
		*itr += 1;
		cout << *itr << endl;
	}
	
	List<int>::const_iterator citr = lst.begin();
	for (; citr != lst.end(); ++citr)
	{
		cout << *citr << endl;
	}

	lst.pop_back();
	cout << "size1: " << lst.size() << endl;

	lst.pop_front();
	cout << "size2: " << lst.size() << endl;

	lst.clear();
	cout << "size3: " << lst.size() << endl;
}