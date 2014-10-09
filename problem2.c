#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int *table, int tablesize)
{
	if(n >= tablesize)
	{
		if(n == 0)
			return 0;
		else if(n==1)
			return 1;
		else
			return fibonacci(n-1,table,tablesize) + fibonacci(n-2,table,tablesize);
	}
	else
		return table[n];
}

int main()
{
	int table[100];
	int tablesize;
	int fibonacci_number;
	int i;

	int sum_of_evens;

	tablesize = 0;
	fibonacci_number = 0;
	sum_of_evens = 0;
	
	while((table[tablesize] = fibonacci(fibonacci_number, table, tablesize)) < 4000000)
	{
		tablesize++;
		fibonacci_number++;
	}

	for(i=0;i<tablesize;i++)
	{
		if(table[i]%2 == 0)
		{
			printf("Fibonacci %i: %i\n", i, table[i]);
			sum_of_evens += table[i];
		}
	}

	printf("Sum of even fib numbers under 4,000,000: %i\n",sum_of_evens);
	return 0;
}
