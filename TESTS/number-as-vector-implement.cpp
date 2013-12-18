//included libs
#include <iostream>
#include <vector>

using namespace std;

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

void correct (vector<unsigned short> &number, int position = 0, int system = 10) //correct function
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

void add (vector<unsigned short> &number, int addition = 1)
{
	number.at(0) += addition;
	correct(number);
}


int main()
{
    vector<unsigned short> number (1);

    for (int i = 0; i < 200; i++)
    {
        add(number);
    }
    printCount(number);

	return 0;
}
