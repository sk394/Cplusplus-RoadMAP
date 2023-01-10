/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 6B - Farmer's Market I
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose:  write a program that reads a file of information pertaining to a
Farmer’s Market. The file contains the names of various farms participating in a Farmer’s
Market. The program should open and connect to a file object for input, read the data,
perform some calculations, create a report, and then rewrite the information to a new
output file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cin; using std::cout;
using std::endl; using std::string;
using std::ifstream; using std::ofstream;
using std::left; using std::setw; using std::right;
using std::setfill; using std::fixed; using std::showpoint;
using std::setprecision; using std::throw_with_nested; using std::ios;

void processFile(ifstream&, ofstream&);
void openFile(ifstream& file, char fileName[15]) // the variable filename can contain max 14 characters
{
	
	file.open(fileName);
	if (file.is_open()) {
		cout << setfill('=');
		cout<< setw(45) << '\n' << endl;
		cout << "=" << "\t"<< "FARMER'S MARKET INVENTORY";
		cout << "\t   " << right << "=\n" << endl;
		cout << setw(46)<<"\n\n";
		
	}
	else {
		cout << "Unable to open file";
	}
}

int main()
{
	char fileName[15];
	string outputFile;
	cout << "Enter the name of the file(Hint: assign.txt): ";
	cin >> fileName;
	cout << "Enter the file you want to create: ";
	cin >> outputFile;
	//open the file
	ifstream file;
	openFile(file, fileName);
	//create a file with the given string
	ofstream outFile;
	outFile.open(outputFile.c_str());
	//execute the process
	processFile(file,outFile);
	
	//close the file
	file.close();
	return 0;
}


void processFile(ifstream& file, ofstream& outFile)
{
	string farmName; //name of the file, ends with the comma //farmname is max 25 character 
	int countofItem; //number of items
	string item; //Name of the item
	float itemPrice; //unit cost of each item
	double totaPrice; //items * unitPrice
	double sumofPrice=0; //sum of all totalprices
	int totalitem=0;

	 //name of the farm is delimitted with comma with everything else separated by a space
	while (!file.eof()) { // 
		getline(file, farmName, ','); //for the farm name, get the name before the comma
		file>>countofItem >> item >> itemPrice; // it reads the individual data values from the file
		
		totaPrice = (countofItem * itemPrice);
		
		cout << right << setfill(' ') << setw(0) << farmName + ":" << "\t" << countofItem << " " << item << "@ " <<
			itemPrice << " each totalling $" <<fixed<<showpoint<<
			setprecision(2)<< totaPrice << endl;
		cout << "..." << endl;
		totalitem += countofItem; //keeps on adding the items
		sumofPrice += totaPrice; //keeps on adding the sumPrices
		//Rewriting each line of the file into Outfile
		outFile << farmName <<"  "<< countofItem <<" "<<item <<" "<< itemPrice <<"   $"<<fixed<<showpoint<<setprecision(2)<< (countofItem * itemPrice);
	}
	cout << "\nGrand Total: "  << totalitem << " totalling $" <<fixed<<showpoint<<setprecision(2)<< sumofPrice<<endl;
	outFile << "\n\nThere are " << totalitem << " items totalling $" << sumofPrice;
	//pause the screen
	system("pause");
}



