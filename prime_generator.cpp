#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <primesieve.hpp>
using namespace std;

void generate_primes();
unsigned long long digitSum(unsigned long long num);
//string ull_to_string(unsigned long long num);

//http://usablealgebra.landmark.edu/algebra/factoring/divisibility-rules.php
//https:/primes.utm.edu/howmany.html

int main()
{
	ofstream primes;
	unsigned long long max;
	primesieve::iterator pi;
	uint64_t prime;	

	max = 10000000;
	primes.open("primes_0_1000000.txt");
	
	while(prime = pi.next_prime())
	{
		primes << prime << endl;
		if(prime >= max)
		{
			cout << "Generated all primes below " << max << endl;
			break;
		}
	}

	primes.close();
}

unsigned long long digitSum(unsigned long long num)
{
	unsigned long long sum;
	unsigned long long numCpy;
	sum = 0;
	numCpy = num;
	
	while(numCpy >= 10)
	{
		sum += numCpy%10;
		numCpy/=10;
	}
	sum += numCpy;
	
	return sum;
}
/*
string ull_to_string(unsigned long long num)
{
	unsigned long long numCpy;
	int i;
	string numString;
	string numStringReverse;
	char temp;
	
	numString = "";
	numStringReverse = "";
	numCpy = num;
	
	while(numCpy >= 10)
	{
		temp = numCpy%10 + '0';
		numString += temp;
		numCpy/=10;
	}
	temp = numCpy%10 + '0';
	numString += temp;
	
	for(i=numString.size()-1;i>=0;i--)
		numStringReverse += numString.at(i);
		
	
	return numStringReverse;
}
*/
