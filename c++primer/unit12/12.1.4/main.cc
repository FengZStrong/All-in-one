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

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p){
		disconnect(*p);
	});
}

int main()
{
	destination d;
	f(d);
}