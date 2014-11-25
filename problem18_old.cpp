#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int addFac(int num)
{
	if(num <= 1)
		return 1;
	else
		return num + addFac(num-1);
}

int max(unsigned int x, unsigned int y)
{
	return x>y?x:y;
}

int *get_row_start(int numbers[120], int rowNum)
{
	int LastIndex = addFac(rowNum);
	return &numbers[LastIndex-rowNum];
}

unsigned int greatest_num_from(int numbers[120], int rowNum, int index)
{
	int currentNum = get_row_start(numbers,rowNum)[index];

	if(rowNum == 15)
		return currentNum;
	else
		return currentNum + max(greatest_num_from(numbers, rowNum+1, index), greatest_num_from(numbers, rowNum+1, index+1));
}

int main()
{
	int i;
	int numbers[120] = {75, 95, 64, 17, 47, 82, 18, 35, 87, 10, 20, 4, 82, 47, 65, 19, 1, 23, 75, 3, 34, 88, 2, 77, 73, 7, 63, 67, 99, 65, 4, 28, 6, 16, 70, 92, 41, 41, 26, 56, 83, 40, 80, 70, 33, 41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
	//int numbers[120] = {3,7,4,2,4,6,8,5,9,3};

	/*
	for(i=1;i<=15;i++)
	{
		cout << "Row " << i << ":" << "[";
		for(int j=0;j<i;j++)
		{
			cout << get_row_start(numbers,i)[j];
			if(j+1 != i)
				cout << ", ";
		}
		cout << "]" << endl;
	}
	*/

	unsigned int maximumTotal = greatest_num_from(numbers,1,0);
	cout << "Maximum Total: " << maximumTotal << endl;

	return 1;
}

