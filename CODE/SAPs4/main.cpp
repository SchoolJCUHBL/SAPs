#include "main.hpp"
#include "numlib.h"
#include "CoordinatesConvert.h"

int checkInput()
{
    int n = 0;
    //prompt user for length
    cout << "Enter the length in steps of the SAP (integer, even, larger or equal to 4) : ";
    cin  >> n;

    while ((n % 2) != 0 || n < 4) {
        cout << "Error, Wrong number! Please enter an even integer, larger or equal to 4 : ";
        cin  >> n;
    }
    return n;
}

void initVector(vector<bool> &grid, int gridsize)
{
    for (int i = 0; i < (gridsize); i++)
    {
        grid.push_back (false);
    }
}

void initForbidden(vector<bool> &grid, int gridsize, int height, int width)
{
    for (int i = 0; i < width; i++)
    {
        grid.at(i) = true;
        grid.at(gridsize - width + i) = true;
    }
    for (int i = 0; i < height; i++)
    {
        grid.at(width * i) = true;
        grid.at(width * i + (width - 1)) = true;
    }
    for (int i = 0; i < height/2; i++)
    {
        grid.at(width * i + 1) = true;
    }
}

void printVector(vector<bool> &grid, int gridsize, int width, int height)
{
    int j = height;
    cout << endl;
    for (int i = 0; i < (gridsize) ;i++ )
    {
        if (i%width == 0)
        {
            cout << endl << setw(3) << --j << " | " << setw(3) << translateYtoMan(j, height) << "\t";
        }
        cout << grid.at(i) << " ";
    }
    cout << endl << endl << "\t       ";
    for (int i = 0; i < (width) ;i++ )
    {
        cout << translateXtoMan(i) << " ";
    }
    cout << endl << "\t\t";
    for (int i = 0; i < (width) ;i++ )
    {
        cout << "--";
    }
    cout << endl << "\t\t";
    for (int i = 0; i < (width) ;i++ )
    {
        cout << i << " ";
    }
    cout << endl;
}

void delVector(vector<bool> &grid)
{
    grid.clear();
    grid.shrink_to_fit();
}

void takeStep(vector<bool> &grid, int X, int Y, int rest)
{

}

int main()
{
    vector<bool> grid;
    int SAPlength = checkInput();

    cout << "SAP length is: " << SAPlength << endl;

    int width = (SAPlength/2)+2;
    int height = SAPlength+1;
    int gridlength = height*width;

    initVector(grid, gridlength);
    initForbidden(grid, gridlength, height, width);

    printVector(grid, gridlength, width, height);

    delVector(grid);
    return 0;
}
