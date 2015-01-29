#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

bool isIncreasingVect(vector<int> num)
{
	int i;

	for(i=0;i<num.size()-1;i++)
		if(num[i] > num[i+1])
			return false;

	return true;
}

bool isDecreasingVect(vector<int> num)
{
	int i;
	int j;

	for(j=0;j<num.size();j++)
		if(num[j] != 0)
			break;

	for(i=num.size()-1;i>j;i--)
		if(num[i-1] < num[i])
			return false;

	return true;
}

void vectAdd(vector<int> *vect, int num)
{
	int i;
	int remainder;

	remainder = num;

	for(i=(*vect).size()-1;i>=0;i--)
	{
		if(i == 0)
		{
			(*vect)[i] = (*vect)[i] + remainder;
			break;
		}

		int temp = (*vect)[i] + remainder;
		remainder = temp/10;
		(*vect)[i] = temp%10;

		if(remainder == 0)
			break;
	}
}

int main()
{
	vector<int> vect;
	unsigned int bouncyNumbers;
	int i;

	bouncyNumbers = 0;

	for(i=0;i<11;i++)
		vect.push_back(0);

	while(vect[0] == 0)
	{
		vectAdd(&vect,1);

		if(!(isIncreasingVect(vect)) && !(isDecreasingVect(vect)))
			bouncyNumbers++;
	}

	cout << "Bouncy numbers: " << bouncyNumbers << endl;

	return 1;
}
