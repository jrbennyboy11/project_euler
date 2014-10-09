#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	vector<unsigned long long> triangleNumbers;
	int i;
	int j;
	int currNumDivisors;
	unsigned long long current;

	i = 1;
	triangleNumbers.push_back(1);

	while(true)
	{
		triangleNumbers.push_back(triangleNumbers[i-1] + i + 1);
		currNumDivisors = 2;
		current = triangleNumbers[i];

		for(j=2;j<floor(sqrt(current));j++)
		{
			if(current%j == 0)
				currNumDivisors+=2;
		}

		if(currNumDivisors > 500)
		{
			cout << "Solution: " << current << endl;
			return 1;
		}

		i++;
	}

	return 0;
}
