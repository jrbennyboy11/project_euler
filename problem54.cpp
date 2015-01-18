#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int valueOfHand(string hand[5])
{
	/*
		1. High Card: Highest value card.
		2. One Pair: Two cards of the same value.
		3. Two Pairs: Two different pairs.
		4. Three of a Kind: Three cards of the same value.
		5. Straight: All cards are consecutive values.
		6. Flush: All cards of the same suit.
		7. Full House: Three of a kind and a pair.
		8. Four of a Kind: Four cards of the same value.
		9. Straight Flush: All cards are consecutive values of same suit.
		10. Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
	*/

	int returnVal = 1;
	int i;

	int values[13];
	int suits[4]; //H, D, C, S
	bool hasHand[9];

	for(i=0;i<13;i++)
		values[i] = 0;
	for(i=0;i<4;i++)
		suits[i] = 0;
	for(i=0;i<9;i++)
		hasHand[i] = false;

	//Breakdown of hand into arrays
	for(i=0;i<5;i++)
	{
		if(hand[i].substr(0,1) == "2")
			values[0]++;
		if(hand[i].substr(0,1) == "3")
			values[1]++;
		if(hand[i].substr(0,1) == "4")
			values[2]++;
		if(hand[i].substr(0,1) == "5")
			values[3]++;
		if(hand[i].substr(0,1) == "6")
			values[4]++;
		if(hand[i].substr(0,1) == "7")
			values[5]++;
		if(hand[i].substr(0,1) == "8")
			values[6]++;
		if(hand[i].substr(0,1) == "9")
			values[7]++;
		if(hand[i].substr(0,1) == "T")
			values[8]++;
		if(hand[i].substr(0,1) == "J")
			values[9]++;
		if(hand[i].substr(0,1) == "Q")
			values[10]++;
		if(hand[i].substr(0,1) == "K")
			values[11]++;
		if(hand[i].substr(0,1) == "A")
			values[12]++;

		if(hand[i].substr(1,1) == "H")
			suits[0]++;
		if(hand[i].substr(1,1) == "D")
			suits[1]++;
		if(hand[i].substr(1,1) == "C")
			suits[2]++;
		if(hand[i].substr(1,1) == "S")
			suits[3]++;
	}

	//No need to check if they have high card

	//Check for one pair
	for(i=0;i<13;i++)
	{
		if(values[i] >= 2)
		{
			hasHand[0] = true;
			break;
		}
	}

	//Check for two pair
	if(hasHand[0])
	{
		bool passedOne = false;

		for(i=0;i<13;i++)
		{
			if(values[i] >= 2)
			{
				if(passedOne)
				{
					hasHand[1] = true;
					break;
				}
				else
					passedOne = true;
			}
		}
	}

	//Check for 3 of a kind
	if(hasHand[0])
	{
		for(i=0;i<13;i++)
			if(values[i] >= 3)
			{
				hasHand[2] = true;
				break;
			}
	}

	//Check for straight
	for(i=0;i<=8;i++)
	{
		if(values[i] == 1)
		{
			int j = 0;
			for(j=1;j<5;j++)
			{
				if(values[j+i] != 1)
				{
					i = 13;
					j = 5;
				}
			}

			if(i != 13)
				hasHand[3] = true;
			i = 13;
		}
	}

	//Check for flush
	for(i=0;i<4;i++)
	{
		if(suits[i] == 5)
			hasHand[4] = true;
	}

	//Check for full house
	hasHand[5] = hasHand[2] && hasHand[1];

	//Check for 4 of a kind
	if(hasHand[2])
	{
		for(i=0;i<13;i++)
			if(values[i] == 4)
				hasHand[6] = true;
	}

	//Check for straight flush
	hasHand[7] = hasHand[3] && hasHand[4];

	//Check for royal flush
	hasHand[8] = hasHand[7] && (values[12] == 1);

	for(i=8;i>=0;i--)
		if(hasHand[i] == true)
		{
			returnVal = i+2;
			i = -1;
		}

	return returnVal;
}

int tieBreak(string hand1[5], string hand2[5], int tieType)
{
	int i;
	int values1[13];
	int values2[13];
	int valuesDif[13];

	for(i=0;i<13;i++)
	{
		values1[i] = 0;
		values2[i] = 0;
		valuesDif[i] = 0;
	}

	//Breakdown of hands into arrays
	for(i=0;i<5;i++)
	{
		//Hand 1
		if(hand1[i].substr(0,1) == "2")
			values1[0]++;
		if(hand1[i].substr(0,1) == "3")
			values1[1]++;
		if(hand1[i].substr(0,1) == "4")
			values1[2]++;
		if(hand1[i].substr(0,1) == "5")
			values1[3]++;
		if(hand1[i].substr(0,1) == "6")
			values1[4]++;
		if(hand1[i].substr(0,1) == "7")
			values1[5]++;
		if(hand1[i].substr(0,1) == "8")
			values1[6]++;
		if(hand1[i].substr(0,1) == "9")
			values1[7]++;
		if(hand1[i].substr(0,1) == "T")
			values1[8]++;
		if(hand1[i].substr(0,1) == "J")
			values1[9]++;
		if(hand1[i].substr(0,1) == "Q")
			values1[10]++;
		if(hand1[i].substr(0,1) == "K")
			values1[11]++;
		if(hand1[i].substr(0,1) == "A")
			values1[12]++;
		//Hand 2
		if(hand2[i].substr(0,1) == "2")
			values2[0]++;
		if(hand2[i].substr(0,1) == "3")
			values2[1]++;
		if(hand2[i].substr(0,1) == "4")
			values2[2]++;
		if(hand2[i].substr(0,1) == "5")
			values2[3]++;
		if(hand2[i].substr(0,1) == "6")
			values2[4]++;
		if(hand2[i].substr(0,1) == "7")
			values2[5]++;
		if(hand2[i].substr(0,1) == "8")
			values2[6]++;
		if(hand2[i].substr(0,1) == "9")
			values2[7]++;
		if(hand2[i].substr(0,1) == "T")
			values2[8]++;
		if(hand2[i].substr(0,1) == "J")
			values2[9]++;
		if(hand2[i].substr(0,1) == "Q")
			values2[10]++;
		if(hand2[i].substr(0,1) == "K")
			values2[11]++;
		if(hand2[i].substr(0,1) == "A")
			values2[12]++;
	}
	for(i=0;i<13;i++)
		valuesDif[i] = values1[i]-values2[i];

	switch(tieType)
	{
	case 2: //One Pair
	case 3: //Two Pairs
		for(i=12;i>=0;i--)
		{
			if((!(values1[i] == 2 && values2[i] == 2)) && (values1[i] == 2 || values2[i] == 2 ))
			{
				if(values1[i] == 2)
					return 1;
				else
					return 2;
			}
		}
		for(i=12;i>=0;i--)
		{
			if(valuesDif[i] < 0)
				return 2;
			if(valuesDif[i] > 0)
				return 1;
		}
		return 0;
		break;
	case 4: //Three of a Kind
		for(i=12;i>=0;i--)
		{
			if((!(values1[i] == 3 && values2[i] == 3)) && (values1[i] == 3 || values2[i] == 3 ))
			{
				if(values1[i] == 3)
					return 1;
				else
					return 2;
			}
		}
		for(i=12;i>=0;i--)
		{
			if(valuesDif[i] < 0)
				return 2;
			if(valuesDif[i] > 0)
				return 1;
		}
		return 0;
		break;
	case 7: //Full House
		for(i=12;i>=0;i--)
		{
			if((!(values1[i] == 3 && values2[i] == 3)) && (values1[i] == 3 || values2[i] == 3 ))
			{
				if(values1[i] == 3)
					return 1;
				else
					return 2;
			}
		}
		for(i=12;i>=0;i--)
		{
			if((!(values1[i] == 2 && values2[i] == 2)) && (values1[i] == 2 || values2[i] == 2 ))
			{
				if(values1[i] == 2)
					return 1;
				else
					return 2;
			}
		}
		for(i=12;i>=0;i--)
		{
			if(valuesDif[i] < 0)
				return 2;
			if(valuesDif[i] > 0)
				return 1;
		}
		return 0;
		break;
	case 8: //Four of a Kind
		for(i=12;i>=0;i--)
		{
			if((!(values1[i] == 4 && values2[i] == 4)) && (values1[i] == 4 || values2[i] == 4 ))
			{
				if(values1[i] == 4)
					return 1;
				else
					return 2;
			}
		}
	default: //High Card, Straight, Flush, Straight Flush, Royal Flush
		for(i=12;i>=0;i--)
		{
			if(valuesDif[i] < 0)
				return 2;
			if(valuesDif[i] > 0)
				return 1;
		}
		return 0;
	}
	return 0;
}

int main()
{
	string hand1[5];
	string hand2[5];
	int player1_wins;
	int player2_wins;
	int i;
	int lineNum;
	ifstream pokerHands;
	pokerHands.open("p054_poker.txt");

	i = 0;
	player1_wins = 0;
	player2_wins = 0;
	lineNum = 1;


	while(!pokerHands.eof() && lineNum < 1001)
	{
		lineNum++;
		for(i=0;i<5;i++)
			pokerHands >> hand1[i];
		for(i=0;i<5;i++)
			pokerHands >> hand2[i];

		int hand1val = valueOfHand(hand1);
		int hand2val = valueOfHand(hand2);

		if(hand1val == hand2val)
		{
			int tiebreak = tieBreak(hand1,hand2,hand1val);

			if(tiebreak == 0)
			{
				cout << "There was a tie" << endl;
				cout << "Hand1: [ ";
				for(i=0;i<5;i++)
					cout << hand1[i] << " ";
				cout << "]" << endl;
				cout << "Hand2: [ ";
				for(i=0;i<5;i++)
					cout << hand2[i] << " ";
				cout << "]" << endl;
			}
			else
				tiebreak==1?player1_wins++:player2_wins++;
		}
		else
			hand1val>hand2val?player1_wins++:player2_wins++;

	}

	cout << "Player 1 Won: " << player1_wins << " times" << endl;
	cout << "Player 2 Won: " << player2_wins << " times" << endl;

	pokerHands.close();
}
