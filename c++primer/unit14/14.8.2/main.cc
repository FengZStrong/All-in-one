#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	//auto vec = {2, 4, 6, 8};
	std::vector<int> vec{2, 4, 6, 8};
	std::cout << "type: " << typeid(vec).name() << std::endl;
	std::modulus<int> mod;
	int input = 0;
	std::cin >> input;
	auto is_divisible = std::all_of(vec.begin(), vec.end(), [&](int i) {
		auto res = mod(input, i);
		std::cout << "res:  " << res << std::endl;
		return res == 0;
	});

	std::cout << (is_divisible ? "Yes" : "No") << std::endl;
}