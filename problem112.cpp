#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumVectorReverse(unsigned int num)
{
	vector<int> numVect;
	int currNum;
	unsigned int remainingNum;

	currNum = 0;
	remainingNum = num;

	while(remainingNum >= 10)
	{
		currNum = (int)(remainingNum%10);
		remainingNum /= 10;
		numVect.push_back(currNum);
	}

	numVect.push_back((int)remainingNum);

	return numVect;
}

vector<int> getNumVector(unsigned int num)
{
	vector<int> reverse;
	vector<int> numVect;

	reverse = getNumVectorReverse(num);

	while(reverse.size() > 0)
	{
		numVect.push_back(reverse.back());
		reverse.pop_back();
	}

	return numVect;
}

bool isIncreasingVect(vector<int> num)
{
	int i;

	for(i=0;i<num.size()-1;i++)
		if(num[i] > num[i+1])
			return false;

	return true;
}

bool isIncreasing(unsigned int num)
{
	vector<int> numVect = getNumVector(num);
	return isIncreasingVect(numVect);
}

bool isDecreasing(unsigned int num)
{
	vector<int> numVect = getNumVectorReverse(num);
	return isIncreasingVect(numVect);
}

int main()
{
	unsigned int count;
	unsigned int bouncyNumbers;
	double proportion;

	count = 100;
	bouncyNumbers = 0;
	proportion = 0.0;

	while(proportion < 0.99)
	{
		count++;

		if(!(isIncreasing(count)) && !(isDecreasing(count)))
			bouncyNumbers++;

		proportion = bouncyNumbers/(double)count;
	}

	cout << "Count: " << count << endl;
	cout << "Bouncy Numbers: " << bouncyNumbers << endl;

	cout << "Proportion: " << proportion << endl;
	cout << "Last number: " << count << endl;

	return 1;
}
