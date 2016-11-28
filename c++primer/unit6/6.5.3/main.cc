#include <iostream>
#include <vector>

using namespace std;

int show_vec(vector<int> vec)
{
	if(vec.size() != 0)
	{
		cout << vec[vec.size() - 1] << " ";
#ifndef NDEBUG
		cout << "FUNC:" << __func__ << ": the size of vector is:" << vec.size() << endl;
#endif
		vec.pop_back();
		show_vec(vec);
	}
}

int main()
{
	vector<int> vec{1,2,3,4,5,6,7,8,9,10};
	show_vec(vec);
}