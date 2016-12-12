void swap(int *x, int *y);
void bubbleSort(int *array, int size);

void swap(int *x, int *y)
{
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void bubbleSort(int *array, int size)
{
	if(size <= 0)
		return;
	
	for (int j = size - 1; j > 0; --j) {
		for (int i = 0; i < j; ++i) {
			if (array[i] < array[i + 1]) {
				swap(&array[i], &array[i + 1]);
			}
		}
	}
}