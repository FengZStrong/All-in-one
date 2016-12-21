#include <iostream>
#include "Message.h"

using namespace std;

int main() {
	Message hw("Hello world!");
	Folder f;
	f.addMsg(&hw);
}