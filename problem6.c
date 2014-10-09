#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double sum_of_square(int n)
{
	long double answer;
	double i;

	answer = 0;	
	i = 1;

	for(i=1;i<=n;i++)
		answer += pow(i, 2.0);

	return answer;
}

long double square_of_sum(int n)
{
	long double answer;
	double i;

	answer = 0;	
	i=1;

	for(i=1;i<=n;i++)
		answer += i;

	return pow(answer, 2.0);
}

int main()
{
	long double answer;
	int num;

	num = 100;

	answer = square_of_sum(num) - sum_of_square(num);

	printf("Sum square difference for %i: %Lf\n", num, answer);
	return 0;
}
