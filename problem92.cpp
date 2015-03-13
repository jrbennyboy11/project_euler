#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	const unsigned long long LESS_THAN = 10000000;
	vector<unsigned long long> num_chain;
	std::vector<unsigned long long>::iterator it;
	unsigned long long i;
	unsigned long long num;
	unsigned long long nextNum;
	unsigned long long endless_loops;
	bool repeat;
	
	num = 0;
	endless_loops = 0;
	
	for(i=0;i<LESS_THAN;i++)
	{
		repeat = false;
		num = i;
		
		while(!repeat && num != 89)
		{
			nextNum = 0;
			
			while(num >= 10)
			{
				nextNum += pow(num%10,2);
				num /= 10;
			}
			nextNum += pow(num%10,2);
			
			for(it = num_chain.begin(); it != num_chain.end(); ++it)
				if(*it == nextNum)
					repeat = true;
			
			num_chain.push_back(nextNum);
			num = nextNum;
		}
		
		if(num == 89)
			endless_loops++;
		
		num_chain.clear();
	}
	
	cout << endless_loops << " number chains under " << LESS_THAN << " arrived at 89" << endl;
}