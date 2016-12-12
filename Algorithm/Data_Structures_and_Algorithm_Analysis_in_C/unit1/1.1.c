#include "stdio.h"
#include "BubbleSort.h"

int a[] = {2,3,4,51,31,41,132,2,34,512,313,414};

void func1(int *array, int size, int k)
{
	if ( 0 <= k < size ) {
		bubbleSort(array, size);
		printf("%d\n", array[k]);
	}
}

int main()
{
	func1(a, 12, 5);
}