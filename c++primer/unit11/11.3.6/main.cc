#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

const map<string, string> build_map(ifstream &map_file)
{
	map<string, string> m;
	string key, value;
	while (map_file >> key && getline(map_file, value))
	{
		if(value.size() > 0)
		{
			m[key] = value.substr(1);
		}
	}
	return m;
}

const string &transform(const string &s, const map<string, string> &m)
{
	auto iter = m.find(s);
	if (iter != m.cend())
	{
		return iter->second;
	}
	return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = build_map(map_file);
	// for (const auto &m : trans_map)
	// {
	// 	cout << "key: " << m.first << ", value: " << m.second << endl;
	// }
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}

			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		ifstream map_file(argv[1]);
		ifstream input(argv[2]);
		word_transform(map_file, input);
	}
}