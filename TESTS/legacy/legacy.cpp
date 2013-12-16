//included libraries list
#include <iostream>

using namespace std;

void resetArray (bool **grid, int square)
{
        for (int i = 0; i < square; i++) {
            for (int j = 0; j < square; j++) {
               grid[i][j] = false;
            }
    }
}

void showArray (bool **grid, int square)
{
    for(int i=0; i<square; i++)    //This loops on the rows.
	{
        for(int j=0; j<square; j++) //This loops on the columns
		{
			cout << grid[i][j]  << "  ";
		}
		cout << endl;
	}
}

//function Main starts the execution
int main()
{
    const int SAPlength = 20;

    bool grid[SAPlength][SAPlength];

    resetArray(grid, SAPlength);
    showArray(grid, SAPlength);

    return 0;
}
