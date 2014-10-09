#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream numberList;
	int i;
	int j;
	int numbers[100][50];
	int solution[50];
	int sum;
	int remainder;

	numberList.open("problem13.txt");

	sum = 0;
	remainder = 0;

	/*initialization of double array containing
	 * the grid of numbers pulled from a text file
	 */
	for(i=0;i<100;i++)
	{
		for(j=0;j<50;j++)
		{
			char temp;
			numberList >> temp;
			numbers[i][j] = temp - 48;
		}
	}

	for(i=49;i>=0;i--)
	{
		sum = 0;

		for(j=0;j<100;j++)
			sum += numbers[j][i];

		remainder += sum;

		if(remainder > 10 && i != 0)
			solution[i] = remainder%10;
		else
			solution[i] = remainder;

		remainder -= solution[i];

		if(remainder > 0)
			remainder = remainder/10;
	}

	cout << "Solution: ";
	for(i=0;i<50;i++)
			cout << solution[i];
	cout << endl;
}
