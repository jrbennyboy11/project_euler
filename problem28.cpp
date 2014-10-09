#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

unsigned int **generateSpiral(unsigned int size);
unsigned int diagonalSum(unsigned int **spiral, unsigned int size);

int main()
{
	int i;
	int j;
	unsigned int spiral_size = 1001;
	unsigned int **spiral = generateSpiral(spiral_size);
	unsigned int diagonal_sum = diagonalSum(spiral,spiral_size);

	cout << "A " << spiral_size << " by " << spiral_size << " spiral has a diagonal sum of: " << diagonal_sum << endl;

	/*
	for(i=0;i<spiral_size;i++)
	{
		for(j=0;j<spiral_size;j++)
		{
			if(spiral[i][j] < 10)
				cout << " ";
			cout << spiral[i][j] << " ";
		}

		cout << endl;
	}
	cout << endl;
	*/

	return 1;
}

unsigned int **generateSpiral(unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int num;
	unsigned int direction; //0 = right-down, 1 = left-up
	unsigned int numSpaces;
	unsigned int maxSize;

	unsigned int **spiral = (unsigned int**)malloc(size*sizeof(unsigned int*));

	for(i=0;i<size;i++)
		spiral[i] = (unsigned int*)malloc(size*sizeof(unsigned int));

	i = size/2;
	j = size/2;
	num = 1;
	direction = 0;
	numSpaces = 0;
	maxSize = size*size;

	spiral[i][j] = num;

	while(numSpaces != size && num!=maxSize)
	{
		numSpaces++;

		switch(direction)
		{
		case 0:
			for(k=0;k<numSpaces && num!=maxSize;k++)
				spiral[i][++j] = ++num;
			for(k=0;k<numSpaces && num!=maxSize;k++)
				spiral[++i][j] = ++num;
			break;
		case 1:
			for(k=0;k<numSpaces && num!=maxSize;k++)
				spiral[i][--j] = ++num;
			for(k=0;k<numSpaces && num!=maxSize;k++)
				spiral[--i][j] = ++num;
			break;
		}

		direction = (direction+1)%2;
	}

	return spiral;
}

unsigned int diagonalSum(unsigned int **spiral, unsigned int size)
{
	unsigned int i;
	unsigned int sum = spiral[size/2][size/2];

	for(i=0;i<size/2;i++)
		sum += spiral[i][i] + spiral[size-1-i][size-1-i] + spiral[i][size-1-i] + spiral[size-1-i][i];

	return sum;
}
