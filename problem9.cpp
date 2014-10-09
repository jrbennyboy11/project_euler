#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int i;
	int j;
	int k;

	for(c=3;c<998;c++)
	{
		for(b=c-1;b>0;b--)
		{
			for(a=b-1;a>0;a--)
			{
				if(a+b+c == 1000 && pow((double)a,2.0)+pow((double)b,2.0)==pow((double)c,2.0))
				{
					cout << a << " * " << b << " * " << c << " = " << a*b*c << endl;
				}
			}
		}
	}
}
