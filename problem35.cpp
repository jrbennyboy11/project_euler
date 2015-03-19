#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

unsigned int num_digits(unsigned int num);
vector<unsigned int> get_rotations(unsigned int num);

int main()
{
	ifstream primes;
	vector<unsigned int> primeVect;
	vector<unsigned int> rotations;
	std::vector<unsigned int>::iterator it;
	std::vector<unsigned int>::iterator it2;
	std::vector<unsigned int>::iterator it3;
	unsigned int num;
	unsigned int circular_primes;
	bool is_circular_prime;
	bool found;
	
	num = 0;
	circular_primes = 0;
	
	/*
	for(unsigned int i=980;i<=990;i++)
	{
		rotations = get_rotations(i);
		cout << "Rotations of " << i << ": [" << rotations[0];
		for(unsigned int j=1;j<rotations.size();j++)
			cout << ", " << rotations[j];
		cout << "]" << endl;
	}
	*/
	
	primes.open("primes_0_1000000.txt");
	while(!primes.eof() && num < 1000000)
	{
		primes >> num;
		primeVect.push_back(num);
	}
	primes.close();

	for(it = primeVect.begin(); it != primeVect.end() && *it < 1000000; it++)
	{
		rotations = get_rotations(*it);
		is_circular_prime = true;

		for(it2 = rotations.begin(); it2 != rotations.end()-1 && is_circular_prime; it2++)
		{
			found = false;

			for(it3 = primeVect.begin(); *it3 <= *it2 && !found; it3++)
				if(*it2 == *it3)
					found = true;

			if(!found)
				is_circular_prime = false;
		}

		if(is_circular_prime)
			circular_primes++;

		rotations.clear();
	}

	cout << "Number of circular primes below 1000000: " << circular_primes << endl;
}

unsigned int num_digits(unsigned int num)
{
	unsigned int numCpy = 0;
	unsigned int numDigits = 1;

	numCpy = num;
	while(numCpy >= 10)
	{
		numCpy /= 10;
		numDigits++;
	}

	return numDigits;
}

vector<unsigned int> get_rotations(unsigned int num)
{
	vector<unsigned int> rotations;
	unsigned int numDigits = num_digits(num);
	unsigned int numCpy = 0;
	unsigned int currentNum;
	unsigned int digits[numDigits];
	unsigned int tensPlace;
	unsigned int i;
	unsigned int j;

	numCpy = num;

	for(i=0;i<numDigits;i++)
	{
		digits[numDigits-i-1] = numCpy%10;
		numCpy /= 10;
	}

	/*
	cout << "Digits of " << num << ": [" << digits[0];
	for(i=1;i<numDigits;i++)
		cout << ", " << digits[i];
	cout << "]" << endl;
	*/

	for(i=0;i<numDigits;i++)
	{
		currentNum = 0;
		tensPlace = 1;
		for(j=0;j<numDigits-1;j++)
			tensPlace *= 10;

		for(j=(i+1)%numDigits;j!=i;j=(j+1)%numDigits)
		{
			currentNum += digits[j] * tensPlace;
			tensPlace /= 10;
		}
		currentNum += digits[j];

		rotations.push_back(currentNum);
	}
	
	return rotations;
}


