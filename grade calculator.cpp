/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 2A - Grade Calculator
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: a program that calculates the total grade for N classroom
exercises as a percentage
*/

#include <iostream>


using namespace std;

int main(){
    int classRoom_exer, scoreReceived, pointsPossible; //the user inputs these values and classRoom_exer must be >0
    double sum1, sum2;
    double percentage, totalsum;
    int i = 1; //the loop starts from first exercise
        cout<<"How many exercises to input? ";
        cin>>classRoom_exer;
    while (i <= classRoom_exer){
        cout<<"Score received for exercise "<<i<<": ";
        cin>>scoreReceived;
        sum1 += scoreReceived;

        cout<<"Total Points possible for exercise "<<i<<": ";
        cin>>pointsPossible;
        sum2 += pointsPossible;
         i++;

         percentage = (sum1/sum2)*100; //percentage is calculated by dividing points scored by points possible and multiplying by 100
    }


        cout<<"Your total is "<<sum1 <<" out of "<<sum2 <<" , or "<<setprecision(4)<< percentage <<"%"<<endl;

    char letterGrade;
    if (percentage >= 93 && percentage <= 100){   //conditional statements check for the true and false conditions
        letterGrade = 'A';
    }else if (percentage >= 90){
        letterGrade = 'A-';
    }else if (percentage >= 87){
        letterGrade = 'B+';
    }else if (percentage >= 83){
        letterGrade = 'B';
    }else if (percentage >= 80){
        letterGrade = 'B-';
    }else if (percentage >= 77){
        letterGrade = 'C+';
    }else if (percentage >= 73){
        letterGrade = 'C';
    }else if (percentage >= 70){
        letterGrade = 'C-';
    }else if (percentage >= 67){
        letterGrade = 'D+';
    }else if (percentage >= 63){
        letterGrade = 'D';
    }else if (percentage >= 60){
        letterGrade = 'D-';
    }else{
        letterGrade = 'F';
    }

        cout<<"Your letter grade is "<<letterGrade<<endl;

    return 0;
}

