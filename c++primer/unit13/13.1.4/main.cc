#include <iostream>
using namespace std;

struct Numbered
{
	int mysn;
	Numbered() : mysn(rand() % 100) {}
	Numbered(const Numbered &n) : mysn(rand() % 100) {}
};

void f(const Numbered &s)
{
	cout << "f:" << s.mysn << endl;
}

int main()
{
	Numbered a, b = a, c = b;
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
	f(a);
	f(b);
	f(c);
}