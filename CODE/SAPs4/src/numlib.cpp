//included libs
#include "numlib.h"

//function main starts the execution

void printCount (vector<unsigned short> &number) //print number
{
	string output;
	for (int i = number.size()-1; i >= 0; i--)
	{
		cout << number.at(i);
	}
	cout << endl;
}

void correct (vector<unsigned short> &number, int position, int system) //correct function
{
	while (number.at(position) > system-1)
	{
		number.at(position) -= system;
		if (position != number.size()-1)
		{
			number.at(position+1)++;
		}
		else
		{
			number.emplace_back(1);
		}
		correct(number, position+1);
	}
}

void add (vector<unsigned short> &number, int addition)
{
	number.at(0) += addition;
	correct(number);
}
