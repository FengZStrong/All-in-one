#include <iostream>
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

string& StrBlob::front() const
{
	check(0, "f");
	cout << "const front" << endl;
	return data->front();
}

string& StrBlob::back()
{
	check(0, "b");
	return data->back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this, 0);
}

const StrBlobPtr StrBlob::begin() const
{
	return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

//******************
//Class StrBlobPtr
//******************

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (sz > ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "++");
	++curr;
	return *this;
}