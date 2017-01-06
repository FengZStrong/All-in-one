template <typename Object>
class List
{
private:
	struct Node
	{
		Object data;
		Node *prev;
		Node *next;
		Node(const Object &o = Object(), Node *p = nullptr, Node *n = nullptr) : data(o), prev(p), next(n) {}
	};
public:
	class const_iterator
	{
	public:
		const_iterator() : current(nullptr) { }
		const Object& operator*() const { return retrieve(); }
		const_iterator& operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator& operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		const_iterator& operator--()
		{
			current = current->prev;
			return *this;
		}
		bool operator==(const const_iterator &rhs) { return current == rhs.current; }
		bool operator!=(const const_iterator &rhs) { return !(*this == rhs); }
	protected:
		Node *current;
		Object& retrieve() const { return current->data; }
		const_iterator(Node *n) : current(n) { }
		friend class List<Object>;
	};

	class iterator : public const_iterator
	{
	public:
		iterator() { }
		Object& operator*() { return this->retrieve(); }
		const Object& operator*() const { return const_iterator::operator*(); }
		iterator& operator++()
		{
			this->current = this->current->next;
			return *this;
		}
		iterator& operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		iterator& operator--()
		{
			this->current = this->current->prev;
			return *this;
		}
	protected:
		iterator(Node *n) : const_iterator(n) { }
		friend class List<Object>;
	};

public:
	List() { init(); }
	~List() 
	{
		clear();
		delete head;
		delete tail;
	}
	List(const List &rhs)
	{
		init();
		*this = rhs;
	}
	List& operator=(const List &rhs)
	{
		if (this != &rhs)
		{
			clear();
			for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
				push_back(*itr);

		}
		return *this;
	}
	iterator begin() { return iterator(head->next); }
	const_iterator begin() const { return const_iterator(head->next); }
	iterator end() { return iterator(tail); }
	const_iterator end() const { return const_iterator(tail); }
	int size() const { return theSize; }
	bool empty() const { return size() == 0; }
	void clear()
	{
		while (!empty())
			pop_front();
	}
	Object& front() { return *begin(); }
	const Object& front() const { return *begin(); }
	Object& back() { return *--end(); }
	const Object& back() const { return *--end(); }
	void push_back(const Object &o) { insert(end(), o); }
	void push_front(const Object &o) { insert(begin(), o); }
	void pop_back() { erase(--end()); }
	void pop_front() { erase(begin()); }
	iterator insert(iterator itr, const Object &o)
	{
		Node *p = itr.current;
		++theSize;
		Node *newNode = new Node(o, p->prev, p);
		p->prev->next = newNode;
		p->prev = newNode;
		return iterator(newNode);
	}
	iterator erase(iterator itr)
	{
		Node *p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		--theSize;
		return retVal;
	}
	iterator erase(iterator start, iterator end)
	{
		for (iterator itr = start; itr != end;)
			itr = erase(itr);
		return end;
	}
private:
	int theSize;
	Node *head;
	Node *tail;
	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};