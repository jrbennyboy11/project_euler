#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

unsigned int triangular_number(unsigned int n);
unsigned int pentagonal_number(unsigned int n);
unsigned int hexagonal_number(unsigned int n);

int main()
{
	vector<unsigned int> t;
	vector<unsigned int> p;
	vector<unsigned int> h;
	unsigned int i;
	unsigned int j;
	unsigned int k;
	unsigned int max;
	bool found;
	
	max = 10000;
	found = false;
	i = 144;
	
	while(!found)
	{
		for(;i<max;i++)
		{
			t.push_back(triangular_number(i));
			p.push_back(pentagonal_number(i));
			h.push_back(hexagonal_number(i));
		}
		
		for(i=0;i<t.size() && !found;i++)
			for(j=0;p[j]<=t[i] && !found;j++)
				if(t[i] == p[j])
					for(k=0;h[k]<=p[j] && !found;k++)
						if(p[j] == h[k])
						{
							found = true;
							cout << "T(" << i+143 << ") = P(" << j+143 << ") = H(" << k+143 << ")" << endl;
							cout << "T(" << i+143 << ") = " << t[i] << endl;			
						}
		
		i = max;
		max *= 10;
	}
	
	return 0;
}

unsigned int triangular_number(unsigned int n)
{
	return n*(n+1)/2;
}

unsigned int pentagonal_number(unsigned int n)
{
	return n*(3*n-1)/2;
}

unsigned int hexagonal_number(unsigned int n)
{
	return n*(2*n-1);
}