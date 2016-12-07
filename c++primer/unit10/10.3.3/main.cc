#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	//10.20
	vector<string> vec = {"hello", "world", "polylink", "1", "aaa"};
	int count = count_if(vec.begin(), vec.end(), [](string &s) -> bool {
		if(s.size() > 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	});

	cout << "cout : " << count << endl;

	//10.21
	int i = 100;
	auto f = [&i]() -> bool {
		while (i > 0)
		{
			--i;
		}

		if (i == 0)
		{
			return true;
		}

		return false;
	};

	if (f())
	{
		cout << "Now 'i' is 0." << endl;
	}
}