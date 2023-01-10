/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 8B - Encryption
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: we will imagine that our country is at war and our enemies are using a
secret code to communicate with each other. We have managed to intercept the message
as follows:
:mmZ\dxZmx]Zpgy
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector;


int main()
{
	char encoded[] = " :mmZ\\dxZmx]Zpgy";  //decrypts the given encoded message

	    	//decryption formula is :
	    /*If(Encrypted – Key < 32) then
	    		DecryptedChar = 127 – (32 – (Encrypted – Key)) //algebric arithmetic used
	    		Else
	    		DecryptedChar = (Encrypted – Key)
	    		*/
	vector<string> decodedMessage; //store the decrypted message in the vector

	for (int key = 1; key < 101; key++)   //use the for loop to decrypt the message
	{
		string temp; //temporary string to store the decrypted message
		for (int i = 1; i < strlen(encoded); i++)
		{
			if (encoded[i] - key < 32)
			{
				temp += char(127 - (32 - (encoded[i] - key)));
			}
			else
			{
				temp += char(encoded[i] - key);
			}
		}
		decodedMessage.push_back(temp);
	}
	//print the decrypted message

		for (int i = 0, k =1; i < decodedMessage.size(); i++)
		{
			cout << "Key " << k << " Decoded Message: " << decodedMessage[i] << endl;
			cout << endl;
			k++;
		}

	return 0;

}
















