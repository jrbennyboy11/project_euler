#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

const int gridSize = 80;

unsigned int find_min_path(int grid[gridSize][gridSize]);
unsigned int find_min_path_helper(int grid[gridSize][gridSize], int x, int y, unsigned int currentSum);
unsigned int myMin(unsigned int num1, unsigned int num2);

int main()
{
	ifstream matrixFile;
	int i;
	int j;
	
	int grid[gridSize][gridSize];
	
	matrixFile.open("p081_matrix.txt");
	
	for(i=0;i<gridSize;i++)
	{
		char temp;
		
		for(j=0;j<gridSize;j++)
		{
			matrixFile >> grid[i][j];
			matrixFile >> temp;
		}
	}
	
	matrixFile.close();
	
	/*
	for(i=0;i<gridSize;i++)
	{
		for(j=0;j<gridSize;j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	cout << "Minimum Path: " << find_min_path(grid) << endl;
}

unsigned int find_min_path(int grid[gridSize][gridSize])
{
	return find_min_path_helper(grid, 0, 0, 0);
}

unsigned int find_min_path_helper(int grid[gridSize][gridSize], int x, int y, unsigned int currentSum)
{
	currentSum += grid[x][y];
	
	if(x == gridSize-1 && y == gridSize-1)
		return currentSum;
	//row
	else if(x == gridSize-1)
		return currentSum + find_min_path_helper(grid, x, y+1, currentSum);
	//column
	else if(y == gridSize-1)
		return currentSum + find_min_path_helper(grid, x+1, y, currentSum);
	else
		return myMin(currentSum + find_min_path_helper(grid, x, y+1, currentSum),currentSum + find_min_path_helper(grid, x+1, y, currentSum));
}

unsigned int myMin(unsigned int num1, unsigned int num2)
{
	return num1>num2?num2:num1;
}