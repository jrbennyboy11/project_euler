#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

void generate_primes();
unsigned long long digitSum(unsigned long long num);
//string ull_to_string(unsigned long long num);

//http://usablealgebra.landmark.edu/algebra/factoring/divisibility-rules.php

int main()
{	
	generate_primes();
}

/*
 * This function assumes that primes.text has all the primes
 * up to 10 already in it. Will fail otherwise.
 */
void generate_primes()
{
	ifstream primes_in;
	ofstream primes;
	string filename;
	unsigned long long start;
	unsigned long long i;
	unsigned long long j;
	bool prime;
	
	filename = "primes.txt";
	start = 0;
	i = 3;
	prime = true;
	
	primes_in.open(filename.c_str());
	while(!primes_in.eof())
	{
		primes_in >> start;
	}
	cout << "Start: " << start << endl;
	primes_in.close();
	
	primes.open(filename.c_str(), std::ofstream::out | std::ofstream::app);
	i = start;
	while(i < ULLONG_MAX)
	{
		i+=2;
		prime = true;
		
		unsigned int temp = i%10;
		if(temp!=1 && temp!=3 && temp!=7 && temp!=9)
			prime = false;
		else
		{
			unsigned long long digit_sum = digitSum(i);
			if(digit_sum%3 == 0)
				prime = false;
		}
		for(j=3;j*j<i && prime;j++)
			if(i%j==0)
				prime = false;
		
		if(prime)
		{
			primes << i << endl;
			cout << "Prime Generated: " << i << endl;
		}
	}
	
	cout << "Unsigned Long Long Max Value Reached" << endl;
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