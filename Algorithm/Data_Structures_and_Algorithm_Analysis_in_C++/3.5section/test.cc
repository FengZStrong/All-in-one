#include <iostream>

int num = 100;

int& getValue()
{
	return num;
}

int getValue1()
{
	return num;
}

int main()
{
	getValue()++;
	std::cout << num << std::endl;
	int tmp = getValue1();
	tmp++;
	std::cout << num << std::endl;
}