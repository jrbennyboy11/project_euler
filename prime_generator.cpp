#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generate_primes(unsigned long long start, unsigned long long end);
string ull_to_string(unsigned long long num);

int main()
{
	unsigned long long start;
	unsigned long long end;
	
	start = 0;
	end = 1000000;
	
	generate_primes(start, end);
}

//Generates prims from start to end-1
void generate_primes(unsigned long long start, unsigned long long end)
{
	ofstream primes;
	string filename;
	unsigned long long i;
	unsigned long long j;
	bool prime;
	
	filename = "primes_" + ull_to_string(start) + "_to_" + ull_to_string(end) + ".txt";
	i = 0;
	prime = true;
	
	primes.open(filename.c_str());
	for(i=start;i<end;i++)
	{
		prime = true;
		
		if(i%10000 == 0)
			cout << "Generated primes up to: " << i << endl;
		
		for(j=2;j<=i/2 && prime;j++)
			if(i%j==0)
				prime = false;
		
		if(prime)
			primes << i << endl;
	}
	
	cout << "Results written to " << filename << endl;
	primes.close();
}

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