#include "StrBlob.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back()
{
	check(0, "p");
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "f");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "b");
	return data->back();
}