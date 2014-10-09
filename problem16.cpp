#include <iostream>
using namespace std;

void arrayMult(int *numArray, int num)
{
	int i;
	int current;
	int remainder;

	current = 0;
	remainder = 0;

	for(i=999;i>0 && i>=(1000-numArray[0]);i--)
	{
		current = numArray[i]*num + remainder;

		remainder = current/10;
		current = current%10;

		numArray[i] = current;
	}

	while(remainder > 10)
	{
		numArray[999 - numArray[0]] = remainder%10;
		numArray[0] = numArray[0]+1;
		remainder /= 10;
	}

	if(remainder > 0)
	{
		numArray[999 - numArray[0]] = remainder;
		numArray[0] = numArray[0]+1;
	}
}

int main()
{
	int solution[1000];
	int i;
	int j;
	int finalAnswer;

	finalAnswer = 0;

	for(i=0;i<999;i++)
		solution[i] = 0;

	solution[999] = 2;
	solution[0] = 1;

	for(i=2;i<=1000;i++)
	{
		/*
		cout << "2^" << i-1 << ": ";
		for(j=1000-solution[0];j<1000;j++)
				cout << solution[j];
		cout << endl;
		*/
		arrayMult(solution, 2);
	}

	for(i=1000-solution[0];i<1000;i++)
		finalAnswer += solution[i];

	cout << "Solution: " << finalAnswer << endl;
}
