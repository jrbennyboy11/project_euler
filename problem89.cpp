#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
  	I = 1
	V = 5
	X = 10
	L = 50
	C = 100
	D = 500
	M = 1000
 */

/*
  	Numerals must be arranged in descending order of size.
	M, C, and X cannot be equalled or exceeded by smaller denominations.
	D, L, and V can each only appear once.
 */

/*
  	Only one I, X, and C can be used as the leading numeral in part of a subtractive pair.
	I can only be placed before V and X.
	X can only be placed before L and C.
	C can only be placed before D and M.
 */

string ull_to_roman(unsigned long long num);
unsigned long long roman_to_ull(string roman);

int main()
{
	ifstream romans;
	string currLine;
	unsigned long long characters_saved;
	
	characters_saved = 0;
	romans.open("p089_roman.txt");
	
	while(!romans.eof())
	{
		getline(romans, currLine);
		
		unsigned long long romanVal = roman_to_ull(currLine);
		string minRoman = ull_to_roman(romanVal);

		characters_saved += currLine.size() - minRoman.size();
	}
	
	romans.close();
	
	cout << characters_saved << " characters were saved" << endl;
	
}

string ull_to_roman(unsigned long long num)
{
	unsigned long long numCpy;
	string roman;
	bool usedD;
	bool usedL;
	bool usedV;
	
	numCpy = num;
	roman = "";
	usedD = false;
	usedL = false;
	usedV = false;
	
	while(numCpy >= 1000)
	{
		roman += "M";
		numCpy -= 1000;
	}
	if(numCpy >= 900)
	{
		roman += "CM";
		numCpy -= 900;
	}
	if(numCpy >= 500)
	{
		roman += "D";
		numCpy -= 500;
		usedD = true;
	}
	if(numCpy >= 400 && !usedD)
	{
		roman += "CD";
		numCpy -= 400;
		usedD = true;
	}
	while(numCpy >= 100)
	{
		roman += "C";
		numCpy -= 100;
	}
	if(numCpy >= 90)
	{
		roman += "XC";
		numCpy -= 90;
	}
	if(numCpy >= 50)
	{
		roman += "L";
		numCpy -= 50;
		usedL = true;
	}
	if(numCpy >= 40 && !usedL)
	{
		roman += "XL";
		numCpy -= 40;
		usedL = true;
	}
	while(numCpy >= 10)
	{
		roman += "X";
		numCpy -= 10;
	}
	if(numCpy >= 9)
	{
		roman += "IX";
		numCpy -= 9;
	}
	if(numCpy >= 5)
	{
		roman += "V";
		numCpy -= 5;
		usedV = true;
	}
	if(numCpy >= 4 && !usedV)
	{
		roman += "IV";
		numCpy -= 4;
		usedV = true;
	}
	while(numCpy > 0)
	{
		roman += "I";
		numCpy--;
	}
	
	return roman;	
}

unsigned long long roman_to_ull(string roman)
{
	unsigned long long values[13];
	unsigned long long val;
	string possibilities[13];
	string romanCpy;
	int i;
	
	val = 0;
	romanCpy = roman;
	
	possibilities[0] = "CM";
	possibilities[1] = "M";
	possibilities[2] = "CD";
	possibilities[3] = "D";
	possibilities[4] = "XC";
	possibilities[5] = "C";
	possibilities[6] = "XL";
	possibilities[7] = "L";
	possibilities[8] = "IX";
	possibilities[9] = "X";
	possibilities[10] = "IV";
	possibilities[11] = "V";
	possibilities[12] = "I";
	
	values[0] = 900;
	values[1] = 1000;
	values[2] = 400;
	values[3] = 500;
	values[4] = 90;
	values[5] = 100;
	values[6] = 40;
	values[7] = 50;
	values[8] = 9;
	values[9] = 10;
	values[10] = 4;
	values[11] = 5;
	values[12] = 1;
	
	
	for(i=0;i<13;i++)
	{
		while(romanCpy.find(possibilities[i]) != string::npos)
		{
			val += values[i];
			romanCpy = romanCpy.substr(0, romanCpy.find(possibilities[i])) + romanCpy.substr(romanCpy.find(possibilities[i])+possibilities[i].size());
		}
	}
	
	return val;
}
/*
I = 1
IV = 4
V = 5
IX = 9
X = 10
XL = 40
L = 50
XC = 90
C = 100
CD = 400
D = 500
CM = 900
M = 1000
*/