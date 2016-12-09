#include <iostream>
#include <memory>

using namespace std;

struct destination
{
	
};

struct connection
{
	
};

connection connect(destination* pd)
{
	connection c;
	return c;
}

void disconnect(connection)
{
	cout << "disconnect" << endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	//unique_ptr<int> up(new int(100));
	//unique_ptr<int> up1 = up;
	//unique_ptr<int> up1(up);

	connection c = connect(&d);
	unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
}

int main()
{
	destination d;
	f(d);

	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);
	//IntP p1(pi);
	IntP p2(pi2);
	//IntP p3(&ix);
	IntP p4(new int(2048111111));
	cout << *p4 << endl;
	{
		//IntP p5(p2.get());
	}

	cout << *p2 << endl;
}