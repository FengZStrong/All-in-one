#include <iostream>
#include <vector>

using namespace std;

//typedef int (*f)(int, int);
using f = int (*)(int, int); 

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	if(y != 0)
		return x / y;
	else
		return 0;
}

vector<f> vec = {add, subtract, multiply, divide};

int main()
{
	for(auto f : vec)
	{
		cout << f(20, 10) << " ";
	}
	cout << endl;
}