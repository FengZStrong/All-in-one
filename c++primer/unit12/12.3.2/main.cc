#include <fstream>
#include <iostream>
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);

	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;

		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ifstream infile(argv[1]);
		runQueries(infile);
	}
}