#include "StrVec.h"

using namespace std;

allocator<std::string> StrVec::alloc;

StrVec::StrVec(initializer_list<string> il) : elements(nullptr), first_free(nullptr), cap(nullptr) {
	for (auto s : il) {
		push_back(s);
	}
}

StrVec::StrVec(const StrVec &s) {
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
	auto newData = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	return *this;
}

StrVec::~StrVec() {
	free();
}

void StrVec::push_back(const std::string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s); // 前置指针
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate() {
	auto newCapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newCapacity);
	auto dest = newData;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}