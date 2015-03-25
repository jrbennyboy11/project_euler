#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
#include "./bennum/Bennum.h"

unsigned long long digitSum(unsigned long long num);

int main()
{
	vector<unsigned long long> terms;
	unsigned long long numerator;
	unsigned long long temp;
	unsigned long long i;
	unsigned long long j;
	unsigned long long k;
	int ktrack;
	Bennum myNum;
	
	numerator = 2;
	terms.push_back(1);
	terms.push_back(2);
	terms.push_back(3);
	ktrack = 0;
	k = 2;
	
	for(i=3;i<=100;i++)
	{
		if(ktrack == 0)
		{
			temp = k;
			k *= 2;
		}
		else
			temp = 1;
		
		numerator = temp*terms[i-1]+terms[i-2];
		terms.push_back(numerator);
				
		ktrack++;
		ktrack%=3;
	}
	
	cout << "Digit sum of " << terms[terms.size()-1] << ": " << digitSum(numerator) << endl;
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
		numCpy /= 10;
	}
	sum += numCpy;
	
	return sum;
}
