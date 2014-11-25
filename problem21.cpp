#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int *properDivisors(int num)
{
	int i;
	vector<int> divisors;
	divisors.push_back(1);

	for(i=2;i<num/2+1;i++)
		if(num%i == 0)
			divisors.push_back(i);

	int *divisorArray = (int*)malloc((divisors.size()+1)*sizeof(int));
	divisorArray[0] = divisors.size();

	for(i=1;i<=divisors.size();i++)
		divisorArray[i] = divisors[i-1];

	return divisorArray;
}

int main()
{
	const int SUM_OF_AMICABLE_NUMBERS_UNDER = 10000;
	vector<int> amicableNumbers;
	unsigned int i;
	unsigned int j;
	unsigned int total;

	int divisorSums[SUM_OF_AMICABLE_NUMBERS_UNDER];
	char amicableTF[SUM_OF_AMICABLE_NUMBERS_UNDER];
	int **divisors = (int**)malloc(SUM_OF_AMICABLE_NUMBERS_UNDER*sizeof(int*));
	total = 0;

	for(i=0;i<SUM_OF_AMICABLE_NUMBERS_UNDER;i++)
		amicableTF[i] = 0;

	for(i=1;i<=SUM_OF_AMICABLE_NUMBERS_UNDER;i++)
		divisors[i-1] = properDivisors(i);

	for(i=0;i<SUM_OF_AMICABLE_NUMBERS_UNDER;i++)
	{
		int total = 0;
		for(j=1;j<=divisors[i][0];j++)
			total += divisors[i][j];
		divisorSums[i] = total;
	}

	/*
	for(i=0;i<10;i++)
	{
		cout << "Proper Divisors of " << i+1 << ": [";
		for(j=1;j<=divisors[i][0];j++)
		{
			cout << divisors[i][j];
			if(j != divisors[i][0])
				cout << ", ";
		}
		cout << "] = " << divisorSums[i] << endl;
	}
	*/

	for(i=0;i<SUM_OF_AMICABLE_NUMBERS_UNDER;i++)
	{
		if(amicableTF[i]==0 && divisorSums[i]<SUM_OF_AMICABLE_NUMBERS_UNDER && divisorSums[i]!=i+1 && divisorSums[divisorSums[i]-1] == i+1)
		{
			amicableNumbers.push_back(i+1);
			amicableNumbers.push_back(divisorSums[i]);
			amicableTF[i] = 1;
			amicableTF[divisorSums[i]-1] = 1;
		}
	}

	cout << "Amicable Numbers under " << SUM_OF_AMICABLE_NUMBERS_UNDER << ":" << endl;
	for(i=0;i<amicableNumbers.size();i++)
	{
		total+=amicableNumbers[i];
		cout << amicableNumbers[i] << endl;
	}

	cout << "Total of these numbers: " << total << endl;

	return 1;
}
