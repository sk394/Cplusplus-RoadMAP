/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 5A - Prime Number
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: we will write a program and an isPrime Function.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using std::cin; using std::cout;
using std::ios; using std::endl;

//create a function names isPrime and take the valid argument( only integer greater than 0)
//user-defined function should be bool since it is asked to return either true or false
//1 is an exception, not a prime number though 1 mod 1 == 0
//check the prime, if it is prime, show all the prime numbers up until that number


bool isPrime(long int num)  //long int since it has 8 bytes and function definition: It has parameter num.
{
   /* int check = 0;     Another way of checking either number is prime or not. This time, we are using boolean function
    if (num<=1){
        check=1;
    }
    for (int i = 2; i< num; i++){
        if(num%i ==0){
            check++;
        }
    }
    return check;
    */
    if (num <=1) return false; //if user entered number is <= 1, the function should return false i.e. not prime
    if (num ==2) return true; //2 is a prime number

    //to check number above 3 we should use the for loop
    for (int i = 2; i < num; i++){ //to check whether the number is divisible by any numbers below the entered number
        if (num % i==0) return false; //any divisible number other than 1 and that number is not a prime number

    }
    return true; //if the condition above doesn't match, that is prime number
}

int main(){
    long int number;
    char userAnswer;
    do{      //repeating until the user no longer wants to make a request
    cout<<"Enter a number to check: ";
    cin>>number;
    //validate the entered number
    do{
        if(cin.fail()|| number < 0){
            cout<<"Error! The wrong input! "<<endl;
            cout<<" Enter another number: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cin>>number;
        }
    }while(!cin || number < 0);

    if (isPrime(number)){
        cout<<number<<" is a prime number.\n"<<endl;
            cout<<"All the prime numbers from 2 up until "<<number<<" are ";
            for (int j = 1; j<=number; j++){   //putting for loop inside the true, easier to print the prime numbers
                if (isPrime(j)){
                cout<<j<<" ";
                }
            }
    }
    else{
        cout<<number<<" is not a prime number."<<endl; //The program ends if the number is not prime
    }
    cout<<"\nDo you want to try another number(Y/N):";
    cin>>userAnswer;

    //Validating userAnswer
    while(cin.fail()|| !(userAnswer =='N'|| userAnswer == 'n' || userAnswer =='Y' || userAnswer =='y')){
          cout<<"Wrong Input! Try one more \n";
            cout<<"Enter (Y/N):";
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
          cin>>userAnswer;
          }
    if (userAnswer=='N' || userAnswer =='n'){
        break;
    }
    }while(userAnswer!='N' || userAnswer !='n');
    return 0;
}
