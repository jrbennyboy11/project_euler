#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream primes;
	vector<unsigned int> primeVect;
	std::vector<unsigned int>::iterator it;
	unsigned int num;
	unsigned int i;
	unsigned int j;
	bool found;
	bool done;
	
	done = false;
	
	primes.open("primes_0_1000000.txt");
	while(!primes.eof() && num < 1000000)
	{
		primes >> num;
		primeVect.push_back(num);
	}
	primes.close();
	
	for(i=3;i<1000000 && !done;i+=2)
	{
		for(it = primeVect.begin(); it != primeVect.end() && *it < i; it++);
		
		if(*it != i)
		{
			found = false;
			for(it = primeVect.begin(); it != primeVect.end() && *it < i && !found; it++)
				for(j=0;(*it+(2*j*j)) <= i;j++)
					if((*it+(2*j*j)) == i)
						found = true;
			
			if(!found)
			{
				cout << i << " cannot be written as the sum of a prime and twice a square" << endl;
				done = true;
			}
		}
	}
}