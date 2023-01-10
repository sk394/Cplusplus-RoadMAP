/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 8A - Pig Latin
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose:  Write a program that reads an input file of sentences and converts each word to “Pig Latin.”
In this program’s version, to convert a word to Pig Latin, you should remove the first letter
and place that letter at the end of the word. Then you append the string “ay” to the word.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring> 
#include <fstream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::ifstream; using std::ofstream;
using std::vector;


void openfile(ifstream& infile) {
	//input file validation
	if (infile.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
}

void readline(ifstream& infile, vector<string>& words)
{
	string line;
	while (!infile.eof())
	{
		infile >> line;   //read line from file
		words.push_back(line);
	}
}

int main()
{
	string filename;
	cout << "Enter the name of the file: ";
	getline(cin, filename);
	ifstream infile(filename.c_str());

	string line;
	vector<string> words;
	vector<string> temp;
	openfile(infile);
	readline(infile, words);

	// convert every words to piglatin
	for (int i = 0; i < words.size(); i++)
	{
		string word = words[i];
		//if the word is not an english word, delete it
		for (int i = 0; i < word.length(); i++) {
			if (!isalpha(word[i])) { // checks whether the word contains alphabet or not
				word.erase(i, 1);
				i--;
			}
		}	
			//piglatin algorithm
			char firstletter = word[0];
			word.erase(0, 1);
			word += firstletter;
			word += "AY";
			// uppercase the word just incase there are some lowercase letters 
			for (int i = 0; i < word.length(); i++) {
				word[i] = toupper(word[i]);
			}
			temp.push_back(word);
		
	}
	//print the pigLatin words
	cout << "The piglatin version of the provided text file is:" << endl;
	cout << endl;
	for (int i = 0; i < words.size(); i++)
	{
		if (i % 5 == 0)  //line break
		{
			cout <<"\n"<< endl;
		}
		cout << temp[i] << " ";
	}
	
	cout << endl;
	infile.close();
	system("pause");

}
			
			
			
			
			
			
			
			
			
			
			
			
					
		
 