#include <iostream>
#include <fstream>
#include "StrBlob.h"

using namespace std;

int main()
{
	ifstream in("input");

	StrBlob sb;
	string text;
	while (getline(in, text))
	{
		sb.push_back(text);
	}
	StrBlobPtr sbs = sb.begin();
	for (unsigned u = 0; u < sb.size(); sbs.incr(), ++u)
	{
		cout << sbs.deref() << endl;
	}

	const StrBlob csb = sb;
	const StrBlobPtr aaa = csb.begin();

	cout << aaa.deref() << endl;
}