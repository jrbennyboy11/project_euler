#include <iostream>
using namespace std;

int main()
{
	unsigned int longestNumber;
	unsigned int longestNumberLength;
	unsigned int i;
	unsigned long long current;
	unsigned int currentLength;

	longestNumber = 0;
	longestNumberLength = 0;

	for(i=2;i<1000000;i++)
	{
		current = i;
		currentLength = 2;

		while(current != 1)
		{
			if(current % 2 == 0)
				current = current/2;
			else
				current = (3 * current) + 1;

			currentLength++;
		}

		if(currentLength > longestNumberLength)
		{
			longestNumber = i;
			longestNumberLength = currentLength;
		}
	}

	cout << "Solution: " << longestNumber << endl;
	cout << "Length: " << longestNumberLength << endl;

	return 1;
}
