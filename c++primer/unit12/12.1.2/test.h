#include <iostream>
class test
{
public:
	test();
	test(int d);
	~test();
	void print();
private:
	int data;
};

test::test() : data(0)
{
	std::cout << "test():" << data << std::endl;
}

test::test(int d) : data(d)
{
	std::cout << "test()" << data << std::endl;
}

test::~test()
{
	std::cout << "~test():" << data << std::endl;
}

void test::print()
{
	std::cout << "print: " << data << std::endl;
}