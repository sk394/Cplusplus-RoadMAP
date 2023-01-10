/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 2B - Ten Numbers
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: a program that that reads in ten whole numbers and that
outputs the sum of all the numbers greater than zero, the sum of all the numbers less than
zero (which will be a negative number or zero), and the sum of all the numbers, whether
positive, negative, or zero.
*/

#include <iostream>
#include <iomanip>
#include "header_suman.h"

using namespace std;


int main(){
    int wholeNumber, sumPositive, sumNegative, totalSum;
    int i= 1;
    sumPositive = 0;
    sumNegative = 0;
    while (i <= 10){
        cout<<"Enter any number ";
        cin>> wholeNumber;


    if (wholeNumber > 0){
        sumPositive += wholeNumber;
    }else {
        sumNegative += wholeNumber;

    }
        i++;

}
 totalSum =sumPositive + sumNegative;
        cout<<"Sum of Positive Numbers: "<<sumPositive<<endl;
        cout<<"Sum of Negative Numbers: "<<sumNegative<<endl;
        cout<<"Sum of all numbers: "<<totalSum<<endl;

        return 0;

}
