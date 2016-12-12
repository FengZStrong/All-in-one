#include <iostream>
#include <sstream>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &in)
{
	string line;
	string word;
	int num = 1;
	while (getline(in, line))
	{
		lineVec.push_back(line);
		istringstream stream(line);
		while (stream >> word)
		{
			//wordMap[word] = word_set;
			auto map_it = wordMap.find(word);
			if (map_it != wordMap.end())
			{
				map_it->second.insert({num});
				//cout << "1,word:" << word << endl;
			}
			else
			{
				set<int> num_set{num};
				wordMap[word] = num_set;
				//cout << "2,word:" << word << endl;
			}
		}
		++num;
	}
	cout << wordMap.size() << endl;
}

void TextQuery::query(std::string &s)
{
	map<string, set<int>>::iterator iter = wordMap.find(s);
	if (iter != wordMap.end())
	{
		set<int> s = iter->second;
		for (auto e : s)
		{
			cout << "(line:" << e << "): " << lineVec[e - 1] << endl;
		}
	}
}

// TextResult TextQuery::query(string s)
// {

// }