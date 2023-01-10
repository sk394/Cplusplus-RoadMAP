/*COPYRIGHT (C) 2022 Suman Khadka (4761417 ) All rights reserved.
Assignment 5B - SportsMania
Author. Suman Khadka
sk394@uakron.edu
Version. 20.03
Purpose: we will write a program that simulates the answer to the greatest
dodgeball player of all time while using functions.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>   //used for RAND_MAX

using std::cin; using std::cout;
using std::rand; using std::endl;
using std::setprecision; using std::showpoint;
using std::fixed; using std::ios;

//Aaron, Bob, and Charlie had an argument over which one of them was the greatest dodgeball player of all time
//To end the argument once and for all, they agreed on a dodgeball due
// Aaron is a poor shooter and only hits his target with a probability of 1 / 3.[Least likely to hit]
//Bob is a bit better and hits his target with a probability of 1/2. [ likely to hit, better than Aaron]
//Charlie is an expert shooterand never misses[best among the best,  most likely to hit, better than everyone]

//Game Sequence: Aaron, followed by Bob, and then by Charlie
//cycle would repeat until one man is left standing and is declared the winner
//

void shoot(bool& targetAlive, double accuracy); //function prototype for shot simulation
int startDuel(); //function prototype to generate the winner
const float AARONACCURACY = 1.0 / 3;
const float BOBACCURRACY = 0.5;
const float CHARLIEACCURACY = 1.0;
const int NUMDUELS = 1000;


int main()
{
	double aaronWins = 0, bobWins = 0, charlieWins = 0; //variables to keep track of the number of wins for each player
	for (int i = 0; i < NUMDUELS; i++) // invoking for 1000 times
	{
		int winnerScore = startDuel(); // either 0, 1, 2
		if (winnerScore == 0)
		{
			aaronWins++; //0 + 1 + 1+ ....
		}
		else if (winnerScore == 1)
		{
			bobWins++;
		}
		else if (winnerScore == 2)
		{
			charlieWins++;
		}

	}
	cout << "Using the strategy of shooting at the best shooter alive, " << endl;
	cout << "but Aaron intentionally misses on the first shot:" << endl;
	cout << "Aaron win %: " <<fixed<<showpoint<<setprecision(2)<< (aaronWins) / NUMDUELS << endl; //to convert in percentage to decimal (dividing by 1000)
	cout << "Bob win %: " <<fixed<<showpoint << setprecision(3) << (bobWins) / NUMDUELS << endl;
	cout << "Charlie win %: " <<fixed<<showpoint<< setprecision(3)<<(charlieWins) / NUMDUELS << endl;

	return 0;
}

void shoot(bool &targetAlive, double accuracy) //simulate a single shot by a player
{
	double random;
	//generate a random number between 0 and 1
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
	random = (double)rand()/RAND_MAX; //RAND_MAX is the maximum value of rand() //eg 0.2, 0.7,
	if (random < accuracy)
	{
		targetAlive = false; // if the random number is less than the accuracy, the target is hit; so alive is false
		}
		else {
		targetAlive = true; // if the random number is greater than the accuracy, the target is missed meaning target is alive
		}
	}

int startDuel() // who won the duel? fight between two shooters
{
	// all contestants are alive so set all to true
	// Strategy is to shoot at the best shooter alive so if Bob is the first one to shoot, he will shoot at Charlie among Charlie and Aaron
	//loop until one player is left alive i.e use while loop
	// A counterintuitive strategy is for Aaron to intentionally miss on his first shot. that means game will start with Bob and Charlie then Aaron
	//first shooter is Bob
	//First round is between Bob and Charlie

	bool aliveAaron = true, aliveBob = true, //all three shooters are alive at the start of the duel alive means true, dead means false.
		aliveCharlie = true;

	while ((aliveAaron && aliveBob) ||  (aliveAaron && aliveCharlie) ||(aliveBob && aliveCharlie)) // while loop to keep the game until one is alive,
		//every round 1 will be dead so two will survive so as long as two are living, loop will be iterated
	{
		//round 1
		if (aliveBob) // Bob is alive and he will shoot at Charlie
		{
			if (aliveCharlie) //Charlie is alive
			{
				shoot(aliveCharlie, BOBACCURRACY); //Bob will shoot at Charlie with accuracy of 0.5. shoot function will be called and will return true or false.
				//If false is returned, Charlie is dead and if statement will be skipped. If true is returned, Charlie is alive and else statement will be executed.
			}
			else if (aliveAaron) // Aaron is alive
			{
				shoot(aliveAaron, BOBACCURRACY); // Bob will shoot at Aaron with accuracy of 0.5. shoot function will be called and will return true or false.
			}
		}
		//round 2
		if (aliveCharlie) //Charlie is alive
		{
			if (aliveBob)
			{
				shoot(aliveBob, CHARLIEACCURACY); // Charlie will shoot at Bob with accuracy of 1.0. shoot function will be called and will return true or false.
			}
			else if (aliveAaron)
			{
				shoot(aliveAaron, CHARLIEACCURACY); // Charlie will shoot at Aaron with his strength(accurracy).
			}
		}
		//round 3
		if (aliveAaron) //either Bob or Charlie is already dead so Aaron will shoot
		{
			if (aliveCharlie) //if Charlie is alive
			{
				shoot(aliveCharlie, AARONACCURACY); //Aaron will shoot at charlie with accuracy of 0.33.
			}
			else if (aliveBob) //if Charlie still gets to live, Aaron will shoot at Bob
			{
				shoot(aliveBob, AARONACCURACY);
			}
		}
	}
	//1 of 3 is alive so needs to return the winner
	int value = (aliveAaron==true) ?  0 : (aliveBob==true) ?  1 :  2; //ternary operator to return the winner
	return value;
}














