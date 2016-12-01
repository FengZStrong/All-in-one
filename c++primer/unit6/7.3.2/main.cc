#include "Screen.h"

int main()
{
	Screen s(5, 5, 'c');
	s.move(2, 2).set('b').display(std::cout).set(2, 4, 'a').display(std::cout);

	std::cout << std::endl;

	const Screen blank(5, 3);
	blank.display(std::cout);
	return 0;
}