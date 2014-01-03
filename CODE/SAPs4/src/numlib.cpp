//included libs
#include "numlib.h"

void printCount (vector<unsigned short> &number) //print number
{
	string output;
	for (int i = number.size()-1; i >= 0; i--)
	{
		output.append(to_string(number.at(i)));
	}
	string::size_type pos =  output.find_first_not_of("0");
	if(pos > 0)
    {
        output.erase(0,pos);
    }

	cout << output << endl;
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

void finalize (vector<unsigned short> &number, vector<vector<unsigned short>> &counters)
{
    int array[] = {counters.at(0).size(),counters.at(1).size(),counters.at(2).size(),counters.at(3).size()};
    int temp = 0;

    for(int i = 0; i < 4; i++)
    {
        if(array[i]>temp)
        temp=array[i];
    }

    for (int i = 0; i<= temp-1;i++)
    {
        number.emplace_back(0);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < counters.at(i).size(); j++)
        {
            number.at(j) += counters.at(i).at(j);
        }
    }

    for (int i = 0; i < number.size(); i++)
    {
        while (number.at(i) > 9)
        {
            number.at(i) -= 10;
            number.at(i+1)++;
        }
    }
}
