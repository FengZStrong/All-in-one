#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

class StrBlobPtr;

class StrBlob
{
public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	std::string& front();
	std::string& front() const;
	std::string& back();
	StrBlobPtr begin();
	const StrBlobPtr begin() const;
	StrBlobPtr end();
	StrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};