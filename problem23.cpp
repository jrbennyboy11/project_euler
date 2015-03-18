#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

bool is_abundant(unsigned int num);

int main()
{
	vector<unsigned int> abundants;
	vector<unsigned int> cannot_be_written;
	std::vector<unsigned int>::iterator it2;
	std::vector<unsigned int>::iterator it3;
	bool can_be_written;
	unsigned int solution;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	
	for(i=12;i<=28123;i++)
		if(is_abundant(i))
			abundants.push_back(i);
	
	for(i=1;i<=28123;i++)
	{
		can_be_written = false;
		if(i%100 == 0)
			cout << "i: " << i << endl;
		
		for(it2 = abundants.begin(); it2 != abundants.end() && *it2 < i && !can_be_written; it2++)
			for(it3 = abundants.begin(); it3 != abundants.end() && *it3 < i && !can_be_written; it3++)
				if(i == *it2+*it3)
					can_be_written = true;
		
		if(!can_be_written)
			cannot_be_written.push_back(i);
	}
	
	solution = 0;
	for(i=0;i<cannot_be_written.size();i++)
		solution += cannot_be_written[i];
	
	cout << "Solution to problem 23: " << solution << endl;
	return 1;
}

bool is_abundant(unsigned int num)
{
	unsigned int i;
	unsigned int divisorSum;
	
	divisorSum = 1;
	
	for(i=2;i<=num/2;i++)
		if(num%i == 0)
			divisorSum += i;
	
	if(divisorSum > num)
		return true;
	return false;
}