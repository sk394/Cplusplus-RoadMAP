//create a header file

#ifndef DynamArray_H
#define DynamArray_H
#include <memory>
/* The function will dynamically allocate a new array and
	it will shift all the arrays values and add 0 in the beginning.
*/

std::unique_ptr<int[]>shift(int arr[], int SIZE) {
	if (NULL == arr)
		return NULL;
	std::unique_ptr<int[]> newCopy(new int[SIZE + 1]);
	newCopy[0] = 0;

	for (int i = 0; i < SIZE; i++)
	{
		newCopy[i+1] = arr[i];
	}
	return newCopy;
}

#endif
