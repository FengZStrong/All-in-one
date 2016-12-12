#include <iostream>
#include "test.h"
#include "TextQuery.h"
using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	string s;
	while (true)
	{
		if (!(cin >> s) || s == "q") break;

		tq.query(s);
	}
}

int main(int argc, char *argv[])
{
	test t;
	cout << t.f.a << endl;

	ifstream in(argv[1]);
	runQueries(in);
}