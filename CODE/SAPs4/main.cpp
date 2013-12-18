#include "main.hpp"

std::vector<bool> grid;

int translateXtoMan(int X)
{
    return --X;
}

int translateXtoMachine(int X)
{
    return ++X;
}

int translateYtoMan(int Y, int height)
{
    return Y-(height/2);
}

int translateYtoMachine(int Y, int height)
{
    return Y+(height/2);
}

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

void initVector(int gridsize)
{
    for (int i = 0; i < (gridsize); i++)
    {
        grid.push_back (false);
    }
}

void initForbidden(int SAPlength, int height, int width)
{
    for (int i = 0; i < width; i++)
    {
        grid.at(i * height) = true;
        grid.at(height - 1 + i * height) = true;
    }
    for (int i = 0; i < height; i++)
    {
        grid.at(i) = true;
        grid.at((0.5 * SAPlength * height - i)) = true;
    }
    for (int i = 0; i < SAPlength - 1; i++)
    {
        grid.at(2 * height - 1 - i) = true;
    }
}

void printVector(int gridsize, int width, int height)
{
    int j = height;
    cout << endl;
    for (int i = 0; i < (gridsize) ;i++ )
    {
        if (i%width == 0)
        {
            cout << endl << translateYtoMan(--j, height) << "\t";
        }
        cout << grid.at(i) << " ";
    }
    cout << endl << "       ";
    for (int i = 0; i < (width) ;i++ )
    {
        cout << translateXtoMan(i) << " ";
    }
    cout << endl;
}

void delVector()
{
    grid.clear();
    grid.shrink_to_fit();
}

int main()
{
    int SAPlength = checkInput();

    cout << "SAP length is: " << SAPlength << endl;

    int width = (SAPlength/2)+2;
    int height = SAPlength+1;
    int gridlength = height*width;

    initVector(gridlength);
    initForbidden(SAPlength, height, width);

    printVector(gridlength, width, height);

    delVector();
    return 0;
}
