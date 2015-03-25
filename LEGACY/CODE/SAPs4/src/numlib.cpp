//included libs
#include "numlib.h"

string printCount (vector<unsigned short> &number) //print number
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

	//cout << output << endl;
	return output;
}

void correct (vector<unsigned short> &number, int position, int system) //correct function
{
	while (number.at(position) > system-1)
	{
		number.at(position) -= system;
		if (position != static_cast<int>(number.size())-1)
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
    long long unsigned int array[] = {counters.at(0).size(),counters.at(1).size(),counters.at(2).size(),counters.at(3).size(),counters.at(4).size(),counters.at(5).size(),counters.at(6).size(),counters.at(7).size()};
    long long unsigned int temp = 0;

    for(int i = 0; i < 8; i++)
    {
        if(array[i]>temp)
        temp=array[i];
    }

    long long unsigned int numsize = number.size();

    for (unsigned int i = 0; i <= ((temp-numsize)+2);i++)
    {
        number.emplace_back(0);
    }

    for (int i = 0; i < 8; i++)
    {
        for (unsigned int j = 0; j < counters.at(i).size(); j++)
        {
            number.at(j) += counters.at(i).at(j);
        }
    }

    for (unsigned int i = 0; i < number.size(); i++)
    {
        if (number.at(i) > 9)
        {
            correct(number, i);
        }
    }
}
