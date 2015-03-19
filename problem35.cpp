#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> get_permutations(unsigned int num);

int main()
{
	ifstream primes;
	vector<unsigned int> primeVect;
	vector<unsigned int> permutations;
	std::vector<unsigned int>::iterator it;
	std::vector<unsigned int>::iterator it2;
	std::vector<unsigned int>::iterator itp;
	unsigned int num;
	unsigned int circular_primes;
	
	circular_primes = 0;
	
	/*
	cout << "returned vector: " << endl;
	for(itp = permutations.begin(); itp != permutations.end(); ++itp)
		cout << *itp << endl;
	*/
	
	primes.open("primes_0_1000000.txt");
	while(!primes.eof())
	{
		primes >> num;
		primeVect.push_back(num);
	}
	primes.close();
	
	for(it = primeVect.begin(); it != primeVect.end(); ++it)
	{
		bool is_circular = true;
		permutations = get_permutations(*it);
		
		for(itp = permutations.begin(); itp != permutations.end() && is_circular; ++itp)
		{
			bool found = false;
			for(it2 = primeVect.begin(); it2 != primeVect.end() && !found; ++it2)
			{
				if(*itp == *it2)
					found = true;
			}
			if(!found)
				is_circular = false;
		}

		if(is_circular)
		{
			cout << "Circular Prime: " << *it << endl;
			circular_primes++;
		}
	}

	cout << "Number of circular primes: " << circular_primes << endl;
}

vector<unsigned int> get_permutations(unsigned int num)
{
	vector<unsigned int> permutations;
	int numDigits;
	unsigned int i;
	unsigned int temp;
	unsigned int tensPlace;
	
	numDigits = 1;
	temp = 10;
	
	while(temp <= num)
	{
		numDigits++;
		temp *= 10;
	}
	
	int digits[numDigits];
	
	if(numDigits == 1)
		permutations.push_back(num);
	else
	{	
		temp = num;
		i = 0;
		while(temp >= 10)
		{
			digits[i++] = temp%10;
			temp /= 10;
		}
		digits[i] = temp;
		
		sort(digits, digits+numDigits);

		do
		{
			tensPlace = 1;
			while(tensPlace <= num)
				tensPlace *= 10;

			temp = 0;

			for(i=0;i<numDigits;i++)
			{
				temp += digits[i] * tensPlace;
				tensPlace/=10;
			}
			
			permutations.push_back(temp/10);
		}
		while (next_permutation(digits,digits+numDigits));
	}
	
	return permutations;
}
