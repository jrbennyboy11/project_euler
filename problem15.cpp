#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

const int GRID_SIZE = 20;
void traverseGrid(unsigned int grid[GRID_SIZE+1][GRID_SIZE+1], int row, int column);
void pad(unsigned int num, unsigned int size);

int main()
{
	unsigned int grid[GRID_SIZE+1][GRID_SIZE+1];
	unsigned int solution;
	unsigned int size;
	unsigned int temp;
	int i;
	int j;

	size = 1;
	temp = 0;

	for(i=0;i<=GRID_SIZE;i++)
	{
		for(j=0;j<=GRID_SIZE;j++)
		{
			if(i == 0 && j == 0)
				grid[i][j] = 0;
			else if(i == 0 || j == 0)
				grid[i][j] = 1;
			else
				grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}

	//traverseGrid(grid, 0, 1);
	//traverseGrid(grid, 1, 0);

	solution = grid[GRID_SIZE][GRID_SIZE];

	/*
	//Begin Grid Printing
	temp = 10;

	while(solution >= temp)
	{
		temp *= 10;
		size++;
	}

	for(i=0;i<=GRID_SIZE;i++)
	{
		for(j=0;j<=GRID_SIZE;j++)
		{
			cout << "[ ";
			pad(grid[j][i], size);
			cout << " ]";
		}
		cout << endl;
	}
	cout << endl;

	//End Grid Printing
	*/

	cout << "A " << GRID_SIZE << "x" << GRID_SIZE << " grid has exactly " << solution << " routes." << endl << endl;
}

void traverseGrid(unsigned int grid[GRID_SIZE+1][GRID_SIZE+1], int row, int column)
{
	int pid = 0;
	grid[row][column]++;

	if((row == GRID_SIZE && column == GRID_SIZE))
		return;
	else if(row == GRID_SIZE && column != GRID_SIZE)
		traverseGrid(grid, row, column+1);
	else if((row != GRID_SIZE && column == GRID_SIZE))
		traverseGrid(grid, row+1, column);
	else
	{
		//if((pid = fork()) == 0)
		traverseGrid(grid, row+1, column);
		traverseGrid(grid, row, column+1);
	}
}

void pad(unsigned int num, unsigned int size)
{
	unsigned int padding;
	unsigned int numDigits;
	int i;

	numDigits = 1;
	i = 10;

	while(num >= i)
	{
		i*=10;
		numDigits++;
	}

	padding = size - numDigits;

	if(padding == 0)
		cout << num;
	else
	{
		for(i=0;i<padding;i++)
		{
			cout << " ";

			if(i == padding/2)
				cout << num;
		}
	}
}
