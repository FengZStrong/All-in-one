#include "StrBlobPtr.h"

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (sz > ret->size())
		throw std::out_of_range(msg);
	return ret;
}