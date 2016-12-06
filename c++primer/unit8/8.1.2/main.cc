#include <iostream>
#include <string>

using namespace std;

istream &process_input(istream &input)
{
	string s;
	while (input >> s)
	{
		input.clear();
	}
	cout << s << endl;
	return input;
}

int main(int argc, char *argv[])
{
	process_input(cin);
	return 0;
}