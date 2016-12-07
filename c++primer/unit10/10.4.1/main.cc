#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vec = {1,2,2,2,2,2,2,3,3,3,1,4,5,6};
	list<int> l;

	unique_copy(vec.cbegin(), vec.cend(), inserter(l, l.begin()));

	for(const int &i : l)
	{
		cout << i << ",";
	}
	cout << endl;
}