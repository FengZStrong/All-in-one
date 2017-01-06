#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include "Stack.h"

using namespace std;

map<string, int> msi{
	{"+", 1},
	{"-", 1},
	{"*", 2},
	{"/", 2},
	{"(", 10},
	{")", -1}
};

int main()
{
	Stack<string> s(0);
	vector<string> postfix(0);
	//string expr("a + b * c + ( d * e + f ) * g");
	string expr("a - b - c");
	istringstream iss(expr);
	string item;
	while (iss >> item)
	{
		if (item == "+" || item == "-" || item == "*" || item == "/" || item == "(")
		{
			if (!s.empty())
			{
				auto it1 = msi.find(item);
				auto it2 = msi.find(s.top());
				if (it1->second <= it2->second) 
				{
					if (s.top() != "(")
					{
						postfix.push_back(s.pop());
						
						if (!s.empty() && item == s.top())
						{
							postfix.push_back(s.pop());
							s.push(item);
						}
						else
						{
							s.push(item);
						}
					}
					else
					{
						s.push(item);
					}
				}
				else
				{
					s.push(item);
				}
			}
			else
			{
				s.push(item);
			}
		}
		else if (item == ")")
		{
			while (s.top() != "(")
				postfix.push_back(s.pop());
			s.pop();
		}
		else
		{
			postfix.push_back(item);
		}
	}

	while (!s.empty())
		postfix.push_back(s.pop());

	string result;
	for (auto it = postfix.begin(); it != postfix.end(); ++it)
		result += *it;

	cout << "result: " << result << endl;
}