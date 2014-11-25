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

unsigned int max(unsigned int x, unsigned int y)
{
	return x>y?x:y;
}

unsigned int *get_row_start(unsigned int *numbers, int rowNum)
{
	int LastIndex = addFac(rowNum);
	return &numbers[LastIndex-rowNum];
}

void rowReplace(unsigned int *numbers, int rowNum)
{
	int i;
	unsigned int *currentRow = get_row_start(numbers,rowNum);
	unsigned int *nextRow = get_row_start(numbers,rowNum+1);

	for(i=0;i<rowNum;i++)
		currentRow[i] += max(nextRow[i],nextRow[i+1]);
}

int main()
{
	unsigned int i;
	unsigned int temp;
	unsigned int numRows;
	unsigned int total;
	ifstream triangleFile;
	vector<int> arrayBuilder;

	numRows = 1;
	total = 1;

	triangleFile.open("problem67.txt");
	while(!triangleFile.eof())
	{
		triangleFile >> temp;
		arrayBuilder.push_back(temp);
	}
	triangleFile.close();

	unsigned int triangle[arrayBuilder.size()-1];

	for(i=0;i<arrayBuilder.size()-1;i++)
		triangle[i] = arrayBuilder[i];

	while(total < arrayBuilder.size()-1)
	{
		numRows++;
		total += numRows;
	}

	for(i=numRows-1;i>1;i--)
		rowReplace(triangle, i);

	unsigned int *topRow = get_row_start(triangle,1);
	unsigned int *secondRow = get_row_start(triangle,2);
	cout << "Maximum Total: " << topRow[0] + max(secondRow[0],secondRow[1]) << endl;

	return 1;
}
