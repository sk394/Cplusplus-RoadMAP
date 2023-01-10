/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 6A - Line Numbers
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: a program that asks the user for the name of a file. The program should display the
contents of the file on the screen. Each line of screen output should be preceded with a line
number, followed by a colon. The line numbering should start at 1.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cin; using std::cout;
using std::endl; using std::string;
using std::ifstream; using std::ofstream;
using std::left; using std::setw;

void processFile(ifstream&);
void openFile(ifstream& file, char fileName[15]) // the variable filename can contain max 14 characters
{
	
	file.open(fileName);
	if (file.is_open()) {
		cout << "Successfully Opened the File and the contents of the file are:" << endl;
	}
	else {
		cout << "Unable to open file";
	}
}

int main()
{
	char fileName[15];
	cout << "Enter the name of the file: ";
	cin >> fileName;
	
	//open the file
	ifstream file;
	openFile(file, fileName);
	
	//execute the process
	processFile(file);
	
	//close the file
	file.close();
	return 0;
}


void processFile(ifstream& file)
{
	string line; // to read the line from the file
	int count = 1;
	int limit = 0;

	while(getline(file,line,',')) // gets the entire line, ',' here is the delimeter, if comma is found, a new line will be formed
	{
		cout << setw(0)<<std::left<< count << ": "<<line << endl;
		limit++; count++;
		
		//after printing 24 lines , the program will pause and wait for the user to press the Enter key
		if (limit % 24 == 0) // program will pause at every 24 lines //when the values of limit is 24, mod 24 will be 0
		{
			cout << "Press Enter to continue...";
			cin.ignore();
			cin.get(); // wait for the user to press the Enter key
		}
		////if count is 3, then stop the count and begin from 1 again
		if (count == 4) //the comparison value is 4 because the count starts from 1 and at 3 lines printing, the count value will be 4
		{
			count = 1;
		}
		
	}
}



