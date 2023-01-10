/*
COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 4A - Who wants to be a millionaire
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: a program that an investor can use to compute future bank
balances

*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>
using std::cin; using std::endl;
using std::cout; using std::fixed;
using std::setprecision; using std::pow;
using std::ios;

double newBalance(double initialBalance, double interestRate);
// This first version of the new balance function computes the
// final account balance that will be reached by starting with
// an initial balance and adding one year's interest at a given
// interest rate (such as 0.05 for 5%). The function works
// correctly for any non-negative arguments
double newBalance(double initialBalance, double interestRate, int n);
// This second version of the new balance function computes the
// final account balance that will be reached by starting with
// an initial balance and adding some n number of years of interest
// at a given interest rate (such as 0.05 for 5%). The interest is added
// once per year and it is applied to the entire balance.
// For example, new_balance(100.00, 0.10, 2) is 121.00 since
// the first year received 10.00 interest (10% of 100) and the
// second year received 11.00 interest (10% of the 110, which
// was the second year's starting balance). The function works
// correctly for any non-negative arguments.
// Notice n is not an appropriate variable name, but will not be
// deducted for this program.
int yearsNeeded(double initialBalance, double interestRate, double goal);
// The years needed function computes the number of years needed for
// a given starting balance to reach a given goal at a certain rate
// of compound interest. The function works correctly for any
// positive arguments.

int main()
{
	double initialDeposit, rate, balance_year, balance_10years;
	int years;

	bool loopflag = true;
	do{
                            cout << " The amount of an initial deposit: ";
	cin >> initialDeposit;
	cout << "Enter the interest rate: ";
	cin >> rate;//input validation
        if (cin.fail()||initialDeposit < 0 || rate < 0){
            cout<<"\nEnter the valid values\n ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    else{
        loopflag = false;
    }
	}while(loopflag);

	balance_year = newBalance(initialDeposit, rate);     //function call for 1 year
	balance_10years = newBalance(initialDeposit, rate, 10); // function call for 10 years
	years = yearsNeeded(initialDeposit, rate, 1000000); // function call for years needed to reach 1 million
	 cout.precision(2);
	 cout.setf(ios::fixed, ios::floatfield);
	cout << "The balance in the account after one year of interest is: $" <<balance_year<< endl;
	cout << "The balance in the account after ten years of compounding interest: $" << balance_10years << endl;
	cout << "The number of years required for the balance to reach at least one million dollars: " << years <<" years"<< endl;
	return 0;
}

double newBalance(double initialBalance, double interestRate)   //function definition for balance after a year
{
	double newBalance1;
	newBalance1 = initialBalance + (initialBalance * (interestRate / 100.00)); //formula for newbalance after a year of interest
	return newBalance1;
}

double newBalance(double initialBalance, double interestRate, int n) //function definition for newbalance after 10 years
{
	double newBalance2;
	newBalance2 = initialBalance * pow((1 + (interestRate / 100.00)), n); //formula for newbalance after n years of interest
	return newBalance2;
}

int yearsNeeded(double initialBalance, double interestRate, double goal)  //function definition for yearsneeded to reach million
{
	int yearsNeeded1;
	yearsNeeded1 = log(goal / initialBalance) / log(1 + (interestRate / 100)); //formula for years needed to reach a goal i.e. A = P(1 + r/100)^t
	return yearsNeeded1;
}




