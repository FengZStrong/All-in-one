#include "Stack.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define CALC(result, num1, num2, symbol) \
	do { \
		int tmp =  num1 symbol num2; \
		ostringstream oss; \
		oss << tmp; \
		result = oss.str(); \
	} while(0) \

int main()
{
	Stack<string> s(0);
	string express("6 5 2 3 + 8 * + 3 + *");
	istringstream iss(express);
	string item;
	while (iss >> item)
	{
		if (item == "+")
		{
			string res;
			CALC(res, stoi(s.pop()), stoi(s.pop()), +);
			s.push(res);
		}
		else if (item == "*")
		{
			string res;
			CALC(res, stoi(s.pop()), stoi(s.pop()), *);
			s.push(res);
		}
		else
		{
			s.push(item);
		}
	}

	cout << "result: " << s.top() << endl;
}