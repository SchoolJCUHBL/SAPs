//included libraries list
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <CL/cl.hpp>
#define __NO_STD_VECTOR

/*
void resetArray (int square, bool grid[][])
{
        for (int i = 0; i < square; i++) {
            for (int j = 0; j < square; j++) {
               block[i][j] = false;
            }
    }
}

void showArray (bool grid[][], int square)
{
    for(int i=0; i<square; i++)    //This loops on the rows.
	{
        for(int j=0; j<square; j++) //This loops on the columns
		{
			cout << block[i][j]  << "  ";
		}
		cout << endl;
	}
}
*/


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
/*
    bool grid[SAPlength][SAPlength]; //creates a 9*9 matrix or a 2d array.

    resetArray(grid, SAPlength);
    showArray(grid, SAPlength)
*/
    return 0;
}

//left+right+up+down == SAPlength
//left <= 0,5*SAPlength-1
//right <= 0,5*SAPlength-1
//up <= 0,5*SAPlength-1
//down <= 0,5*SAPlength-1
//never the same spot within one walk
