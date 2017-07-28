#include "HasPtr.h"

int main()
{
	HasPtr hp1("fuck"), hp2("shit");
	HasPtr hp3 = hp1;
	hp2 = hp1;
}