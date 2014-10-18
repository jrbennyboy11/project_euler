#include <iostream>
using namespace std;

int main()
{
	unsigned int day_of_week;
	unsigned int month;
	unsigned int year;
	unsigned int increase;
	unsigned int sundays;

	day_of_week = 1;
	month = 1;
	year = 1900;
	increase = 0;
	sundays = 0;

	while(year <= 2000)
	{
		switch(month)
		{
		case 1:
			increase = 31;
			break;
		case 2:
			increase = year%4==0?29:28;
			break;
		case 3:
			increase = 31;
			break;
		case 4:
			increase = 30;
			break;
		case 5:
			increase = 31;
			break;
		case 6:
			increase = 30;
			break;
		case 7:
			increase = 31;
			break;
		case 8:
			increase = 31;
			break;
		case 9:
			increase = 30;
			break;
		case 10:
			increase = 31;
			break;
		case 11:
			increase = 30;
			break;
		case 12:
			increase = 31;
			break;
		}

		day_of_week = (day_of_week + increase) % 7;

		if(year >= 1901 && day_of_week == 0)
		{
			cout << "1/" << month << "/" << year << " was a Sunday." << endl;
			sundays++;
		}

		if(month == 12)
		{
			year++;
			month = 1;
		}
		else
			month++;
	}

	cout << "Total Sundays Between 1/1/1901 & 12/31/2000: " << sundays << endl;

	return 0;
}
