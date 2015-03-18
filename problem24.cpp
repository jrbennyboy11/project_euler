#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int i;
	unsigned int index;
	unsigned int nums[] = {0,1,2,3,4,5,6,7,8,9};
	unsigned int totalPermutations;
	unsigned int temp;
	unsigned int *permutations;
	
	totalPermutations = 1;
	index = 0;
	
	for(i=10;i>=1;i--)
		totalPermutations *= i;
	
	cout << "total permutations: " << totalPermutations << endl;
	
	permutations = (unsigned int*)malloc(totalPermutations*sizeof(unsigned int));
	
	do
	{
	    temp = 0;
	    
	    for(i=0;i<10;i++)
	    {
	    	if(temp != 0)
	    		temp *= 10;
	    	
	    	temp += nums[i];
	    }
	    
	    permutations[index++] = temp;
	}
	while (next_permutation(nums,nums+10));
	
	sort(nums,nums+10);
	cout << "Millionth Permutation: " << permutations[1000000-1] << endl;
}
