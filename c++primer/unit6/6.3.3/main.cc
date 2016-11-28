#include <iostream>
#include <string>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}

decltype(odd) &arrQuote(int i)
{
	return (i % 2) ? odd : even;
}

string sarr1[] = {"hello", "world", "!"};
string sarr2[] = {"hello", "polylink", "!"};

string (&f(int i))[3]
{
	return (i % 2) ? sarr1 : sarr2;
}

typedef string sarr_alias[3];
sarr_alias &f_alias(int i)
{
	return (i % 2) ? sarr1 : sarr2;
}

decltype(sarr1) &f_decl(int i)
{
	return(i % 2) ? sarr1 : sarr2;
}

int main()
{
	int (*arr)[5] = arrPtr(1);
	for(int i = 0; i != 5; ++i)
	{
		cout << (*arr)[i] << " ";
	}
	cout << endl;

	int (&arr1)[5] = arrQuote(2);
	for(int i = 0; i != 5; ++i)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;

	string (&sarrA)[3] = f_decl(1);//f_alias(2);//f(1);
	for(const string &s : sarrA)
	{
		cout << s << " ";
	}
	cout << endl;
}