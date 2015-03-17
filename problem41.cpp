#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

bool is_pandigital(unsigned long long num);

int main()
{
	ifstream primes;
	unsigned long long primeNum;
	unsigned long long largestPandigital;
	
	primeNum = 0;
	largestPandigital = 0;
	
	primes.open("primes.txt");
	while(!primes.eof() && primeNum < 1000000000)
	{
		primes >> primeNum;
		if(is_pandigital(primeNum))
		{
			cout << "Largest Pandigital Prime: " << primeNum << endl;
			largestPandigital = primeNum;
		}
	}
	primes.close();
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
			contains[i-1] = true;
		numDigits++;
		numCpy/=10;
	}
	contains[numCpy-1] = true;
	
	for(i=0;i<numDigits;i++)
		if(!contains[i])
			return false;
	return true;
}