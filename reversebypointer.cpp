/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 9A - Reverse C-String using pointers
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: Write a function that takes a C-string as an input parameter and reverses the string.
*/

#include <iostream>
#include <string>
#include <cstring>
#include "reverse.h"

using std::cin; using std::cout;
using std::endl; using std::string;

//function prototype
void *reverse(char *str);

int main()
{
	// these are the test cases
	char str1[] = "time";
	char str2[] = "straw";
	char str3[] = "deliver";
	char str4[] = "star";
	char str5[] = "knits";
	cout << "The strings before reversing: " << endl;
	cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;
	reverse(str1);
	reverse(str2);
	reverse(str3);
	reverse(str4);
	reverse(str5);
	cout << "The strings after reversing: " << endl;
	cout << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << " " << endl;

	system("pause");

}
















