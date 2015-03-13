#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//1_2_3_4_5_6_7_8_9_0

int main()
{
	unsigned long long temp;
	unsigned long long temp2;
	unsigned long long i;
	unsigned long long j;
	unsigned long long solution;
	
	solution = 0;
	temp = 0;
	temp2 = 0;
	
	for(i=1000000000;i<10000000000;i++)
	{
		if(i%10000000 == 0)
			cout << "i: " <<  i << endl;
		
		temp = i*i;
		
		if(temp >= 1020304050607080900 && temp <= 1929394959697989990)
		{
			temp2 = temp;
			
			if(temp2%10 == 0)
			{
				temp2 /= 100;
				bool valid = true;
				
				for(j=9;j>0;j--)
				{
					if(temp2%10 != j)
						valid = false;
					
					temp2 /= 100;
				}
				
				if(valid)
				{
					cout << "Solution: " << i << endl;
					return 1;
				}
			}
		}
	}
	
	return 0;
}