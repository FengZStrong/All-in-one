#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

bool greater_than_6(const string &s, const unsigned &size)
{
	return s.size() <= size ? true : false;
}

int main()
{
	vector<string> vec = {"using", "namespace", "std", "placeholders"};
	cout << "count: " << count_if(vec.begin(), vec.end(), bind(greater_than_6, _1, 6)) << endl;
}