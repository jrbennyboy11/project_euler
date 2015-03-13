#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream successes;
	unsigned int i;
	unsigned int j;
	unsigned int index;
	unsigned int numsBefore[10];
	unsigned int password[10];
	bool numbers[10][10]; //numbers n 0-9 have numbers numbers[n][0-9] before them
	
	for(i=0;i<10;i++)
	{
		numsBefore[i] = 0;
		
		for(j=0;j<10;j++)
			numbers[i][j] = false; 
	}
	
	successes.open("p079_keylog.txt");
	
	for(i=0;i<50;i++)
	{
		char in1;
		char in2;
		char in3;
		
		successes >> in1;
		successes >> in2;
		successes >> in3;
		
		unsigned int in1val = in1-'0';
		unsigned int in2val = in2-'0';
		unsigned int in3val = in3-'0';
		
		//numbers[in1val][in2val] means inval1 is before inval2 in the password
		numbers[in1val][in2val] = true;
		numbers[in1val][in3val] = true;
		numbers[in2val][in3val] = true;
	}
	
	successes.close();
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(numbers[i][j])
				numsBefore[i]++;
	
	index = 9;
	
	/*
	 * Put the numbers in order from ones that are before
	 * the most numbers to the ones that are before the least
	 */
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(numsBefore[j] == i)
				password[index--] = j;
	
	cout << "Password: ";
	for(i=0;i<10;i++)
	{
		/*
		 * If the number isn't before any other numbers
		 * and no numbers are before it, then it doesn't
		 * need to be in the password
		 */
		if(numsBefore[password[i]] == 0)
		{
			bool found = false;
			for(j=0;j<50;j++)
				if(numbers[i][password[i]])
					found = true;
			if(found)
				cout << password[i];
		}
		else
			cout << password[i];
	}
	cout << endl;
}