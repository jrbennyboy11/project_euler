#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned long long solution;
	unsigned long long tensPlace;
	int lastTen[10];
	int remainder;
	int i;
	int j;
	
	remainder = 0;
	tensPlace = 0;
	i = 0;
	j = 0;
	
	for(i=0;i<10;i++)
		lastTen[i] = 0;
	lastTen[9] = 2;
	
	for(i=1;i<7830457;i++)
	{
		remainder = 0;
		
		for(j=0;j<10;j++)
			lastTen[j] *= 2;
		
		for(j=9;j>=0;j--)
		{
			lastTen[j] += remainder;
			remainder = lastTen[j]/10;
			lastTen[j] %= 10;
		}
	}
	
	tensPlace = 1;
	solution = 0;
	
	for(i=9;i>=0;i--)
	{
		solution += lastTen[i]*tensPlace;
		tensPlace*=10;
	}
	
	cout << "Solution: " << (solution*28433+1)%10000000000 << endl;
}