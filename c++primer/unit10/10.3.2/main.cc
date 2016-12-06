#include <iostream>

int main()
{
	auto f = [](const int &x, const int &y) -> int {
		return x + y;
	};

	std::cout << f(10, 20) << std::endl;

	int i = 10;
	auto f2 = [i](const int &x) -> int {
		return i + x;
	};

	std::cout << "f2: " << f2(10) << std::endl;
}