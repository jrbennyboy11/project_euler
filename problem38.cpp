#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool is_pandigital(unsigned long long num);
unsigned long long num_digits(unsigned long long num);

int main()
{
	unsigned long long i;
	unsigned long long j;
	unsigned long long k;
	unsigned long long temp;
	unsigned long long tensPlace;
	unsigned long long totalDigits;
	unsigned long long numDigits;
	unsigned long long currNum;
	unsigned long long largestNum;
	
	largestNum = 0;
	cout << endl;

	for(i=1;i<10000;i++)
	{
		currNum = 0;
		totalDigits = 0;

		for(j=1;totalDigits < 9;j++)
		{
			temp = j * i;
			numDigits = num_digits(temp);
			totalDigits += numDigits;

			if(currNum != 0)
			{
				tensPlace = 1;

				for(k=0;k<numDigits;k++)
					tensPlace *= 10;

				currNum *= tensPlace;
			}
			currNum += temp;
		}
		if(totalDigits == 9)
			if(is_pandigital(currNum))
			{
				cout << currNum << " was made by concatinating " << i << " times 1 through " << j-1 << endl;
				if(currNum > largestNum)
					largestNum = currNum;
			}
	}

	cout << endl << "Largest Number: " << largestNum << endl << endl;
}

bool is_pandigital(unsigned long long num)
{
	unsigned long long numCpy;
	unsigned int i;
	unsigned int numDigits;
	bool contains[9];
	
	numCpy = num;
	numDigits = 1;
	
	for(i=0;i<9;i++)
		contains[i] = false;
	
	while(numCpy >= 10)
	{
		int temp = numCpy%10;
		
		if(temp == 0)
			return false;
		else
			contains[temp-1] = true;
		numDigits++;
		numCpy/=10;
	}
	contains[numCpy-1] = true;
	
	for(i=0;i<numDigits;i++)
		if(!contains[i])
			return false;
	return true;
}

unsigned long long num_digits(unsigned long long num)
{
	unsigned long long numCpy = 0;
	unsigned long long numDigits = 1;

	numCpy = num;
	while(numCpy >= 10)
	{
		numCpy /= 10;
		numDigits++;
	}

	return numDigits;
}
