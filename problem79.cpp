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
	unsigned int k;
	unsigned int index;
	unsigned int numsBefore[10];
	unsigned int password[10];
	unsigned int attempts[50][3];
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
		
		numbers[in1val][in2val] = true;
		numbers[in1val][in3val] = true;
		numbers[in2val][in3val] = true;
		
		attempts[i][0] = in1val;
		attempts[i][1] = in2val;
		attempts[i][2] = in3val;
	}
	
	successes.close();
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(numbers[i][j])
				numsBefore[i]++;
	
	for(i=0;i<10;i++)
	{	
		if(numsBefore[i] == 0)
		{
			bool found = false;
			
			for(j=0;j<50;j++)
				if(attempts[j][0] == i)
					found = true;
			
			if(!found)
				cout << i << " doesn't need to be in the password" << endl;
		}
	}
	
	index = 9;
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			if(numsBefore[j] == i)
				password[index--] = j;
	
	cout << "Password: ";
	for(i=0;i<10;i++)
		cout << password[i];
	cout << endl;
	
	//Password check
	for(i=0;i<50;i++)
	{
		int index1;
		int index2;
		int index3;
		
		for(j=0;j<10;j++)
			if(password[j] == attempts[i][0])
				index1 = j;
		
		for(j=0;j<10;j++)
			if(password[j] == attempts[i][1])
				index2 = j;
		
		for(j=0;j<10;j++)
			if(password[j] == attempts[i][2])
				index3 = j;
		
		if(!((index1 < index2) && (index1 < index3) && (index2 < index3)))
			cout << "Password Failed" << endl;
	}
}