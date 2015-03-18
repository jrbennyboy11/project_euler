#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

unsigned int num_digits(unsigned long long num);

//How many n-digit positive integers exist which are also an nth power

int main()
{
	unsigned int i;
	unsigned int j;
	unsigned long long temp;
	unsigned long long endNum;
	
	i = 1;
	temp = 1;
	endNum = 100000000000000;
	
	while(temp < endNum)
	{
		temp *= 2;
		unsigned int numDigits = num_digits(temp);
		
		cout << temp << " has " << numDigits << " digits" << endl;
		
		if(numDigits > i)
			break;
		
		i++;
	}
	
	cout << "i: " << i << endl;
}

unsigned int num_digits(unsigned long long num)
{
	unsigned long long numCopy = num;
	unsigned int numDigits;
	
	numDigits = 1;
	
	while(numCopy >= 10)
	{
		numDigits++;
		numCopy /= 10;
	}
	
	return numDigits;
}