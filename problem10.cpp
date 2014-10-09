#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int i;
	int j;
	vector<int> primes;
	unsigned long long sum;
	bool prime;
	const int PRIMES_BELOW = 2000000;

	sum = 0;
	primes.push_back(2);
	cout << "primes[0]: 2" << endl;

	for(i=3;i<PRIMES_BELOW;i++)
	{
		prime = true;
		int upperBound = i/2+1;
		if(i%2 != 0)
		{
			for(j=3;j<upperBound && prime;j++)
			{
				if(i%j == 0)
					prime = false;
			}

			if(prime)
			{
				cout << "primes[" << primes.size() << "]: " << i << endl;
				primes.push_back(i);
			}
		}
	}

	for(i=0;i<primes.size();i++)
	{
		sum += primes[i];
	}

	cout << "Sum of all primes under " << PRIMES_BELOW << ": " << sum << endl;
}
