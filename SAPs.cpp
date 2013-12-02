//included libraries list
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <CL/cl.hpp>
#define __NO_STD_VECTOR

//function Main starts the execution
int main()
{
    int SAPlength = 0;

    //prompt user for length
    cout << "Enter the length in steps of the SAP (integer, even, larger or equal to 4) : ";
    cin  >> SAPlength;

    while ((SAPlength % 2) != 0 || SAPlength < 4) {
        cout << "Error, Wrong number! Please enter an even integer, larger or equal to 4 : ";
        cin  >> SAPlength;
    }

    cout << "SAP length is: " << SAPlength << endl;
    return 0;
}

//left+right+up+down == SAPlength
//left <= 0,5*SAPlength-1
//right <= 0,5*SAPlength-1
//up <= 0,5*SAPlength-1
//down <= 0,5*SAPlength-1
//never the same spot within one walk
