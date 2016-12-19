#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i) { std::cout << "copy constructor func" << std::endl; }
	std::string *ps;
private:
	int i;
};