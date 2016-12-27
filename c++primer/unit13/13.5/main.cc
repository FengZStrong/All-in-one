#include "StrVec.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	StrVec sv;
	sv.push_back("elem1");

	StrVec sv1{"1", "2", "3"};
	cout << "size: " << sv1.size() << ", capacity: " << sv1.capacity() << endl;
}