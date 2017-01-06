template <typename Object>
class Stack
{
public:
	enum { SPARE_CAPACITY = 16 };
	Stack(int s = 0) : theSize(s), theCapacity(s + SPARE_CAPACITY)
	{ objects = new Object[theCapacity]; }

	~Stack() { delete [] objects; }
	Stack(const Stack &s) = delete;
	const Stack& operator=(const Stack &rhs) = delete;

	void push(const Object &o)
	{
		if (theSize == theCapacity)
			reserve(theSize * 2 + 1);
		objects[theSize++] = o;
	}

	const Object& pop()
	{
		return objects[--theSize];
	}

	const Object& top() { return objects[theSize - 1]; }

	int size() const { return theSize; }
	int capacity() const { return theCapacity; }
	bool empty() const { return size() == 0; }
private:
	int theSize;
	int theCapacity;
	Object *objects;
	void reserve(int newCapacity)
	{
		if (newCapacity <= theCapacity)
			return;
		Object *oldArray = objects;
		objects = new Object[newCapacity];
		for (int i = 0; i < theSize; ++i)
			objects[i] = oldArray[i];
		theCapacity = newCapacity;
		delete [] oldArray;
	}
};