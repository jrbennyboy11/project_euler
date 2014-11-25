#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int arrayAdd(int *answer, int *num1, int *num2, int startingIndex)
{
	int i;
	int lastNonZero = startingIndex;

	for(i=0;i<1000;i++)
		answer[i] = 0;

	for(i=startingIndex;i>0;i--)
	{
		int sum = num1[i] + num2[i] + answer[i];
		int remainder = 0;

		if(sum >= 10)
		{
			remainder = sum/10;
			sum %= 10;
			answer[i-1] = remainder;
			if(remainder > 0)
				lastNonZero = i-1;
		}
		else if(sum > 0)
			lastNonZero = i;

		answer[i] = sum;
	}

	return lastNonZero;
}

int main()
{
	int fibNMinus2[1000];
	int fibNMinus1[1000];
	int fibN[1000];
	int n;
	int i;

	n = 3;

	for(i=0;i<1000;i++)
	{
		fibNMinus2[i] = 0;
		fibNMinus1[i] = 0;
		fibN[i] = 0;
	}

	/*
	//Test Case for arrayAdd
	fibNMinus2[999] = 6;
	fibNMinus2[998] = 9;
	fibNMinus2[997] = 3;
	fibNMinus2[996] = 2;

	fibNMinus1[999] = 2;
	fibNMinus1[998] = 3;
	fibNMinus1[997] = 2;
	fibNMinus1[996] = 1;

	arrayAdd(fibN, fibNMinus1, fibNMinus2, 999);
	cout << "Sum (Should be 3628): " << fibN[996] << fibN[997] << fibN[998] << fibN[999] << endl;
	*/


	fibNMinus2[999] = 1;
	fibNMinus1[999] = 1;
	fibN[999] = 2;

	while(fibN[0] == 0)
	{
		int tempArray[1000];
		for(i=0;i<1000;i++)
			tempArray[i] = fibN[i];

		int startingIndex = arrayAdd(fibNMinus2, fibN, fibNMinus1, 999);

		for(i=0;i<1000;i++)
		{
			fibN[i] = fibNMinus2[i];
			fibNMinus2[i] = fibNMinus1[i];
			fibNMinus1[i] = tempArray[i];
		}
		n++;

		/*
		cout << "Fibonacci(" << n << "): ";
		for(i=startingIndex;i<1000;i++)
			cout << fibN[i];
		cout << endl << endl;
		*/
	}

	cout << "The first Fibonacci sequence to contain 1000 digits is: " << n << endl;

	return 1;
}
