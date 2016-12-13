#include <sstream>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &is) : file(make_shared<vector<string>>())
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		unsigned n = file->size();
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
			{
				lines = make_shared<set<line_no>>();
				//lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata = make_shared<set<line_no>>();
	auto lines = wm.find(sought);
	if (lines != wm.end())
	{
		return QueryResult(sought, file, lines->second);
	}
	return QueryResult(sought, file, nodata);
	
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << endl;

	for (auto num : *(qr.lines))
		os << "\t(line " << num << ") " << *(qr.file->begin() + num - 1) << endl;
	
	return os;
}