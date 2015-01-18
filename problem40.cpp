#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int nth_digit_champernownes_constant(int n)
{
	unsigned int counter = 1;
	unsigned int totalDigits = 1;

	unsigned int numDigits = 1;
	unsigned int tensTracker = 10;
	int returnVal = -1;

	if(n >= 0)
	{
		while(totalDigits < n)
		{
			counter++;

			if(counter == tensTracker)
			{
				tensTracker *= 10;
				numDigits++;
			}

			totalDigits += numDigits;
		}

		int place = totalDigits - n;

		for(int i=0;i<place;i++)
			counter /= 10;


		returnVal = counter%10;
	}

	return returnVal;
}

int main()
{
	int d1;
	int d10;
	int d100;
	int d1000;
	int d10000;
	int d100000;
	int d1000000;

	cout << "d1: " << (d1=nth_digit_champernownes_constant(1)) << endl;
	cout << "d10: " << (d10=nth_digit_champernownes_constant(10)) << endl;
	cout << "d100: " << (d100=nth_digit_champernownes_constant(100)) << endl;
	cout << "d1000: " << (d1000=nth_digit_champernownes_constant(1000)) << endl;
	cout << "d10000: " << (d10000=nth_digit_champernownes_constant(10000)) << endl;
	cout << "d100000: " << (d100000=nth_digit_champernownes_constant(100000)) << endl;
	cout << "d1000000: " << (d1000000=nth_digit_champernownes_constant(1000000)) << endl;

	cout << "Solution: " << d1*d10*d100*d1000*d10000*d100000*d1000000 << endl;
}
