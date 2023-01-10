/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 9B - The Element Shifter
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose:to expand a standard array by dynamically allocating a new
one with a larger footprint. 
*/

#include <iostream>
#include "DynamArray.h"
#include "printarray.h"
#include <memory>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::unique_ptr;


// Function prototypes
unique_ptr<int[]>shift(int arr[], int SIZE); 

void printArray(int arr[], int SIZE); 

int main()
{
	const int SIZE = 5;
	int myNumbers[SIZE] = { 18, 27, 3, 14, 95 };
	// Define a unique_ptr smart pointer, pointing
	// to a dynamically allocated array of integers.
	// A unique_ptr is a small, fast, move-only smart
	// pointer usually used for managing resources
	// with exclusive ownership semantics
	unique_ptr<int[]> newCopy(new int[SIZE + 1]);
	//Before expanding the array
	cout << "Before expanding the array" << endl;
	printArray(myNumbers, SIZE-1);
	
	//after expanding the array
	cout << "\nAfter adding the element to the array" << endl;
	newCopy = shift(myNumbers, SIZE);
	printArray(newCopy.get(), SIZE);
	
	system("pause");
		
}

	
			
			
			
			
			
			
			
			
			
			
			
			
					
		
 