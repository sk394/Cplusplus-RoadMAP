/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 7B - Farmer's Market I Through Bubble Sort Algorithm
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose:  we will read the updated file of information about the Farmer’s Market
named ASSGN6-B.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring> // for strcmp() function

using std::cin; using std::cout;
using std::endl; using std::string;
using std::ifstream; using std::ofstream;
using std::left; using std::setw; using std::right;
using std::setfill;
 using std::ios;

 const int array_size = 28;   //our array size is 28 (from text file)

 // create a structure to hold different data types from the text file into one array variable type
//helpful in sorting operation as we dont need to individually arrange/sort each data type
struct item {
	string farmname;
	int quantity;
	char itemname[10];
	float rate;
	double price;
	int duplicates;
};

void processFile(ifstream& infile);

void openFile(ifstream& file, char fileName[15]) // the variable filename can contain max 14 characters
{

	file.open(fileName);
	if (file.is_open()) {
		cout << setfill('=');
		cout << setw(45) << '\n' << endl;
		cout << "=" << "\t" << "FARMER'S MARKET INVENTORY";
		cout << "\t   " << right << "=\n" << endl;
		cout << setw(46) << "\n\n";

	}
	else {
		cout << "Unable to open file";
	}
}



int main()
{
	char fileName[15];
	string outputFile;
	cout << "Enter the name of the file(Hint: ASSIGN6-B.txt): ";
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

void processFile(ifstream& infile)
{
	struct item items[array_size]; // create a structure variable items
	int sumofitems = 0; // to add all the quantities of the item
    int numOfDuplicates=0;  //to add the loads
	//Step1: read the line from the input stream and get farmname, quantity, itemname, rate and price one at a time and hold it inside an array of structure
	for (int i = 0; i < array_size; i++)   //
	{
		getline(infile, items[i].farmname, ',');
		infile >> items[i].quantity
			>> items[i].itemname
			>> items[i].rate
			>> items[i].price;

	}

	//Step2: use the bubble sort algorithm to sort the array of structure by the item name
	bool swap;
	struct item temp;
	do
	{
		swap = false;
		for (int count = 0; count < (array_size - 1); count++)
		{
			if (strcmp(items[count].itemname, items[count + 1].itemname) > 0)
			{
				temp = items[count];
				items[count] = items[count + 1];
				items[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	//Step3: Remove the duplicate item names from the sorted array structure
	int i = 0;
	item itemz[array_size]; // new structure variable itemz is created to keep the tracks of non-duplicate items
	int counter = 0;
	do {
		int next = 1;
		while (strcmp(items[i].itemname, items[i + next].itemname) == 0) { // if the item name is same as the next item name
			items[i].quantity += items[i + next].quantity;   // add the quantity of the next item to the current item
			items[i].price += items[i + next].price;         // add the price of the next item to the current item
			next++;   // increment the next variable to check the next item (could be more than one duplicates)
		}
		itemz[counter] = items[i];  // store the non-duplicate item in the new structure variable itemz
		itemz[counter].duplicates = next; // store the number of duplicates if found
		counter++;   // increment the counter to keep track of the non-duplicate items
		i += next;   // increment the i variable for checking operation on other items

	} while (i < array_size);


	//Step4: Print the sorted array of structures keeping track of the number of items
	for (int i = 0; i < counter; i++)  //loop only till the counter
	{
		cout << setfill(' ');
		cout << itemz[i].duplicates << " loads of " << itemz[i].itemname << " were delivered " << endl;
		sumofitems += itemz[i].quantity;
		numOfDuplicates +=itemz[i].duplicates;
		cout<<endl;
	}

	cout << "\nThere were " << sumofitems << " items contributed to this week's event." << endl;
	cout<<"Total loads that were delivered: "<<numOfDuplicates;

}



