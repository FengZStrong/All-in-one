#include <iostream>
using namespace std;

struct Numbered
{
	int mysn;
	Numbered() : mysn(rand() % 100) {}
	Numbered(const Numbered &n) : mysn(rand() % 100) {}
	Numbered& operator=(const Numbered &rhs) 
	{
		this->mysn = rand() % 100;
		return *this;
	}
};

void f(const Numbered &s)
{
	cout << "f:" << s.mysn << endl;
}

int main()
{
	Numbered a, b = a, c = b, d;
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
	cout << d.mysn << endl;
	d = a;
	f(a);
	f(b);
	f(c);
	f(d);
}