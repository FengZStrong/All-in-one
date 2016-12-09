#include <iostream>
#include <vector>
#include <memory>
#include "test.h"
using namespace std;

vector<int> *new_vec()
{
	return new vector<int>();
}

vector<int> *add_num()
{
	vector<int> *vec = new_vec();
	int i = 0;
	while (cin >> i)
	{
		vec->push_back(i);
	}
	return vec;
}

shared_ptr<vector<int>> sptr_new_vec()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> sptr_add_num()
{
	shared_ptr<vector<int>> vec = make_shared<vector<int>>();
	int i = 0;
	while (cin >> i)
	{
		vec->push_back(i);
	}
	return vec;
}

int main()
{
	// vector<int> *vec = add_num();
	// for (const int &i : *vec)
	// {
	// 	cout << i << endl;
	// }
	// delete vec;
#if 0
	shared_ptr<vector<int>> sptr_vec = sptr_add_num();
	for (const int &i : *sptr_vec)
	{
		cout << "sptr: " << i << endl;
	}
#endif
	// shared_ptr<int> p(new int(42));
	// int *q = p.get();
	// cout << &q << endl;
	// {
	// 	shared_ptr<int>{q};
	// 	cout  << &q << endl;
	// }
	// int foo = *p;
#if 0
	{
		shared_ptr<test> p(new test(100));
		test *q = p.get();
		cout << &q << endl;
		{
			shared_ptr<test>(q);
			cout << &q << endl;
		}
		cout << "p:" << p.use_count() << endl;
		cout << "111111111" << endl;
		//test foo = *p;
	}

	cout << "222222222" << endl;
#endif

#if 0
	shared_ptr<test> p = make_shared<test>(1110);
	cout << "p:" << p.use_count() << endl;
	{
		//shared_ptr<test> q = p;
		shared_ptr<test> q = make_shared<test>(222);
		cout << "q:" << q.use_count() << endl;
		p = q;
		cout << "-q:" << q.use_count() << endl;
		cout << "-p:" << p.use_count() << endl;
	}

	cout << "out side" << endl;
	cout << "p:" << p.use_count() << endl;
	p->print();
#endif

	double(a)(1.00);
	cout << a;
}