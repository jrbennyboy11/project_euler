#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
	vector<unsigned int> pentagon_numbers;
	vector<unsigned int>::iterator it;
	unsigned int pj;
	unsigned int pk; 
	unsigned int d;
	unsigned int i;
	unsigned int count;
	unsigned int number_of_pentagon_numbers_to_calculate;
	unsigned int increment;
	
	count = 1;
	number_of_pentagon_numbers_to_calculate = 1000;
	increment = 1000;
	
	while(true)
	{
		for(i=1;i<number_of_pentagon_numbers_to_calculate;i++)
		{
			pk = count*(3*count-1)/2;
			count++;
			pentagon_numbers.push_back(pk);
		}
		
		//cout << "Calculated the first " << count << " pentagon numbers." << endl;	
		
		for(i=3;i<(unsigned int)pentagon_numbers.size();i++)
		{
			pk = pentagon_numbers[i];
			
			for(unsigned int i=0;i<(unsigned int)pentagon_numbers.size()-1;i++)
			{
				pj = pentagon_numbers[i];
				
				unsigned int sum = pk-pj;
				unsigned int difference = pk+pj;
				
				it = find(pentagon_numbers.begin(), pentagon_numbers.end(), sum);
				if (it != pentagon_numbers.end())
				{
					it = find(pentagon_numbers.begin(), pentagon_numbers.end(), difference);
					if (it != pentagon_numbers.end())
					{
						d=pk-pj;
						cout << "Pk: " << pk << " | Pj: " << pj << " | D: " << d << endl;
						return 1;
					}
				}
			}
		}
		
		number_of_pentagon_numbers_to_calculate += increment; 
	}
	
	return 0;
}