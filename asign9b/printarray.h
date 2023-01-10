#ifndef PRINTARRAY_H
#define PRINTARRAY_H

// The function will display the elements in the array

void printArray(int arr[], int SIZE)
{
	using namespace std;
	for (int i = 0; i < (SIZE + 1); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
#endif

