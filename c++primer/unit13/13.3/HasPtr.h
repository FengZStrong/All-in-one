#include <string>
#include <iostream>

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);

public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { i = ps->size(); }
	HasPtr(const HasPtr &hp) : ps(new std::string(*(hp.ps))), i(hp.i) { std::cout << "copy constructor func" << std::endl; }
	HasPtr& operator=(HasPtr hp) {
		swap(*this, hp);
		std::cout << "operator=" << std::endl;
		return *this;
	}

	bool operator<(const HasPtr &hp) const;

	~HasPtr() {
		delete ps;
		ps = nullptr;
		//std::cout << "destructor" << std::endl; 
	}
	std::string *ps;
private:
	int i;
};

bool HasPtr::operator<(const HasPtr &hp) const
{
	if (this->i < hp.i)
		return true;
	return false;
}

void swap(HasPtr&, HasPtr&);

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);

	std::cout << "swap" << std::endl;
}