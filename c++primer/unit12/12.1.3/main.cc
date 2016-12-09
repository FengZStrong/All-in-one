#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> p)
{
	cout << "process: " << &p << ", count: " << p.use_count() << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
	cout << "main: " << &p << endl;
	// process(shared_ptr<int>(p));
	// cout << "p:" << *p << ", count:" << p.use_count() << endl;

	process(shared_ptr<int>(p.get()));
	cout << "p:" << *p << ", count:" << p.use_count() << endl;
}