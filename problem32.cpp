#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

bool is_pandigital(unsigned long long num1, unsigned long long num2, unsigned long long num3);

int main()
{
	vector<unsigned long long> products;
	unsigned long long i;
	unsigned long long j;
	unsigned long long k;
	unsigned long long sum;
	unsigned long long product;
	
	sum = 0;
	product = 0;
	
	for(i=1;i<32000;i++)
		for(j=1;j<32000;j++)
		{
			product = i * j;
			
			if(product <= 987654321)
			{
				if(is_pandigital(i,j,product))
				{
					bool found = false;
					
					for(k=0;k<products.size() && !found;k++)
						if(product == products[k])
							found = true;
					
					if(!found)
						products.push_back(product);
					
					cout << i << " x " << j << " = " << product << " is pandigital" << endl;
				}
			}
		}
	
	for(i=0;i<products.size();i++)
		sum += products[i];
	
	cout << "Product Sum: " << sum << endl;
}

bool is_pandigital(unsigned long long num1, unsigned long long num2, unsigned long long num3)
{
	unsigned long long num1Cpy;
	unsigned long long num2Cpy;
	unsigned long long num3Cpy;
	unsigned int i;
	unsigned int numDigits;
	bool contains[9];
	
	num1Cpy = num1;
	num2Cpy = num2;
	num3Cpy = num3;
	
	numDigits = 3;
	
	for(i=0;i<9;i++)
		contains[i] = false;
	
	while(num1Cpy >= 10 || num2Cpy >= 10 || num3Cpy >= 10)
	{
		int temp = 0;
		
		if(num1Cpy >= 10)
		{
			temp = num1Cpy%10;
			if(temp == 0)
				return false;
			else
				contains[temp-1] = true;
			numDigits++;
			num1Cpy/=10;
		}
		
		if(num2Cpy >= 10)
		{
			temp = num2Cpy%10;
			if(temp == 0)
				return false;
			else
				contains[temp-1] = true;
			numDigits++;
			num2Cpy/=10;
		}
		
		if(num3Cpy >= 10)
		{
			temp = num3Cpy%10;
			if(temp == 0)
				return false;
			else
				contains[temp-1] = true;
			numDigits++;
			num3Cpy/=10;
		}
		
		if(numDigits > 9)
			return false;
	}
	if(num1Cpy!=0 && num2Cpy!=0 && num3Cpy!=0)
	{	
		contains[num1Cpy-1] = true;
		contains[num2Cpy-1] = true;
		contains[num3Cpy-1] = true;
	}
	else
		return false;
	
	/*
	 * REMOVE THIS LINE IF REUSING FOR OTHER PROBLEMS
	 */
	if(numDigits != 9)
		return false;
	/*
	 * END OF REMOVE LINE
	 */
	
	for(i=0;i<numDigits;i++)
		if(!contains[i])
			return false;
	return true;
}