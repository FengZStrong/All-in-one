#include <iostream>
#include <vector>
using namespace std;

int &get(int *arry, int index)
{
	return arry[index];
}

void show_vector(vector<int> vec)
{
	if(vec.size() != 0)
	{
		cout << vec[vec.size() - 1] << endl;
		vec.pop_back();
		show_vector(vec);
	}
}

int factorial(int val)
{
	cout << val << endl;
	if (val != 0)
	{
		return factorial(val - 1) * val;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		get(ia, i) = i;
	}
	for(int i = 0; i != 10; ++i)
	{
		cout << ia[i] << " ";
	}
	cout << endl;

	vector<int> vec{1,2,3,4,5};
	show_vector(vec);

	cout << "---factorial---" << endl;
	cout << factorial(5) << endl;
}