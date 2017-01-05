template <typename Object>
class Vector
{
public:
	explicit Vector(int size = 0) 
	: theSize(size), theCapacity(size + SPARE_CAPACITY) 
	{ objects = new Object[theCapacity]; }
	~Vector() { delete [] objects; }
	Vector(const Vector &rhs) { operator=(rhs); }
	Vector& operator=(const Vector &rhs)
	{
		if (this != &rhs)
		{
			delete [] objects;
			theSize = rhs.size();
			theCapacity = rhs.capacity();

			objects = new Object[theCapacity];
			for (int i = 0; i < theSize; ++i)
				objects[i] = rhs[i];
		}

		return *this;
	}

	void resize(int newSize)
	{
		if (newSize > theSize)
			reserve(newSize * 2 + 1);
		theSize = newSize;
	}

	void reserve(int newCapacity)
	{
		if (newCapacity <= theCapacity)
			return;
		
		Object *oldObjs = objects;
		objects = new Object[newCapacity];
		for (int i = 0; i < theSize; ++i)
			objects[i] = oldObjs[i];

		theCapacity = newCapacity;
		delete [] oldObjs;
	}

	Object& operator[](int index) { return objects[index]; }
	const Object& operator[](int index) const { return objects[index]; }
	int size() { return theSize; }
	int capacity() { return theCapacity; }
	bool empty() { return theSize == 0; }
	void push_back(const Object &o)
	{
		if (theSize == theCapacity)
			reserve(theSize * 2 + 1);
		objects[theSize++] = o;
	}
	void pop_back() { --theSize; }
	Object& back() { return objects[theSize - 1]; }

	typedef Object* iterator;
	typedef const Object* const_iterator;
	iterator begin() { return &objects[0]; }
	const_iterator begin() const { return &objects[0]; }
	iterator end() { return &objects[theSize]; }
	const_iterator end() const { return &objects[theSize]; }

	enum { SPARE_CAPACITY = 16 };
private:
	int theSize;
	int theCapacity;
	Object *objects;
};