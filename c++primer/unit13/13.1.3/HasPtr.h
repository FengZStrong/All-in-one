#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new std::string(*(hp.ps))), i(hp.i) { std::cout << "copy constructor func" << std::endl; }
	HasPtr& operator=(const HasPtr &hp) {
		auto newp = new std::string(*hp.ps);
		delete ps;
		ps = newp;
		i = hp.i;
		std::cout << "operator=" << std::endl;
		return *this;
	}

	~HasPtr() {
		delete ps;
		ps = nullptr;
		std::cout << "destructor" << std::endl; 
	}
	std::string *ps;
private:
	int i;
};