#include <iostream>
using namespace std;

// Hamming Weight
int main()
{
	int num = 0;

	while(num >= 0)
	{
		cout << "Enter number: ";
		cin >> num;

		int numOnes = 0;

		while(num > 1)
		{
			numOnes += num%2;
			num /= 2;
		}

		if(num == 1)
			numOnes++;

		cout << "Number of ones: " << numOnes << endl;
	}
}
