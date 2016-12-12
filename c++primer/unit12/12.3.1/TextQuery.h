#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>

class TextResult;

class TextQuery
{
public:
	TextQuery() {}
	TextQuery(std::ifstream &in);
	void query(std::string &s);
	// TextResult query(std::string s);
private:
	std::vector<std::string> lineVec;
	std::map<std::string, std::set<int>> wordMap;
};