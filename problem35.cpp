#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<unsigned int> get_permutations(unsigned int num);

int main()
{
	ifstream primes;
	vector<unsigned int> primeVect;
	vector<unsigned int> permutations;
	std::vector<unsigned int>::iterator it;
	std::vector<unsigned int>::iterator itp;
	unsigned int num;
	unsigned int circular_primes;
	
	circular_primes = 0;
	
	unsigned int testNum = 1234;
	permutations = get_permutations(testNum);
	cout << "returned vector: " << endl;
	for(itp = permutations.begin(); itp != permutations.end(); ++itp)
		cout << *itp << endl;
	
	int i;
	int j;
	for(i=0;i<permutations.size();i++)
		for(j=0;j<permutations.size();j++)
			if(permutations[i] == permutations[j] && j!=i)
				cout << "There is a repeat: " << permutations[j] << endl;
	
	/*
	primes.open("primes_0_1000000.txt");
	while(!primes.eof())
	{
		primes >> num;
		primes.oush_back(num);
	}
	primes.close();
	
	for(it = primeVect.begin(); it != primeVect.end(); ++it)
	{
		permutations = get_permutations(*it);
		for(itp = permutations.begin(); it != permutations.end(); ++it)
		
	}
	*/
}

vector<unsigned int> get_permutations(unsigned int num)
{
	vector<unsigned int> permutations;
	vector<unsigned int> digits;
	unsigned int i;
	unsigned int j;
	int k;
	int numDigits;
	unsigned int temp;
	unsigned int number_of_permutations;
	unsigned int stoppingNumber;
	unsigned int tensPlace;
	
	number_of_permutations = 0;
	numDigits = 1;
	temp = 10;
	i = 1;
	j = 0;
	k = 0;
	
	//calculate number of digits in num
	while(temp <= num)
	{
		numDigits++;
		temp *= 10;
	}
	
	//calculate number of permutations num has
	number_of_permutations = numDigits;
	for(i=numDigits-1;i>1;i--)
		number_of_permutations *= i;
	
	unsigned int permutation_chart[number_of_permutations][numDigits];
	for(i=0;i<number_of_permutations;i++)
		for(j=0;j<numDigits;j++)
			permutation_chart[i][j] = 0;
	
	/*
	cout << "About to begin get_permutations(" << num << ")" << endl;
	cout << num << " has " << number_of_permutations << " permutations" << endl;
	cout << num << " has " << numDigits << " digits" << endl;
	cout << "Permutation Chart: " << endl;
	for(i=0;i<number_of_permutations;i++)
	{
		for(j=0;j<numDigits;j++)
		{
			cout << permutation_chart[i][j];
		}
		cout << endl;
	}
	*/
	
	if(numDigits == 1)
		permutations.push_back(num);
	else
	{	
		temp = num;
		while(temp >= 10)
		{
			digits.push_back(temp%10);
			temp /= 10;
		}
		digits.push_back(temp);
		
		stoppingNumber = number_of_permutations/2;
		
		/*
		cout << "The digits are: [" << digits[0];
		for(i=1;i<numDigits;i++)
			cout << ", " << digits[i];
		cout << "]" << endl;
		*/
		for(i=0;i<number_of_permutations;i++)
			permutation_chart[i][0] = i%numDigits;
		
		for(i=1;i<numDigits;i++)
			for(j=0;j<stoppingNumber;j++)
				permutation_chart[j][i] = (permutation_chart[j][i-1]+(j/numDigits)+1)%numDigits;
		
		for(i=1;i<numDigits;i++)
			for(j=0;j<stoppingNumber;j++)
			{
				k = permutation_chart[j][i-1] - ((j/numDigits)+1)%numDigits;
				
				if(k<0)
					k+=numDigits;
				
				cout << "Minus: " << ((j/numDigits)/2) << endl;
				
				permutation_chart[j+stoppingNumber][i] = k;
			}
			
		cout << "Digits Chart: " << endl;
		for(i=0;i<number_of_permutations;i++)
		{
			for(j=0;j<numDigits;j++)
				cout << permutation_chart[i][j];
			
			cout << endl;
		}

		tensPlace = 1;
		
		for(i=0;i<number_of_permutations;i++)
		{
			while(tensPlace <= num)
				tensPlace *= 10;
			
			temp = 0;
			
			for(j=0;j<numDigits;j++)
			{
				temp += digits[permutation_chart[i][j]] * tensPlace;
				tensPlace/=10;
			}
			
			permutations.push_back(temp/10);
		}
	}
	
	return permutations;
}