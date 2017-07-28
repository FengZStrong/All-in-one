#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) : 
		ps(new string(s)), i(0), use(new size_t(1)) { cout << *ps << ":" << *use << endl; }
	HasPtr(const HasPtr &hp) : 
		ps(hp.ps), i(hp.i), use(hp.use) 
	{
		++*use;
		cout << *ps << ":" << *use << endl;
	}
	HasPtr& operator=(const HasPtr &rhs);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		cout << *ps << ":delete,use:" << *use << endl; 
		delete ps;
		delete use;
	}
	this->ps = rhs.ps;
	this->i = rhs.i;
	this->use = rhs.use;
	cout << *ps << ":" << *use << endl;
	return *this;
}

HasPtr::~HasPtr()
{
	cout << *ps << ":~HasPtr" << endl; 
	if (--*use == 0)
	{
		cout << *ps << ":delete,use:" << *use << endl; 
		delete ps;
		delete use;
	}
}