#include "main.hpp"

std::vector<bool> grid;

int translateX(int X)
{
    return --X;
}

int translateY(int Y, int height)
{
    return Y-(height/2);
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

void printVector(int gridsize, int width, int height)
{
    int j = height;
    cout << endl;
    for (int i = 0; i < (gridsize) ;i++ )
    {
        if (i%width == 0)
        {
            cout << endl << translateY(--j, height) << "\t";
        }
        cout << grid.at(i) << " ";
    }
    cout << endl << "       ";
    for (int i = 0; i < (width) ;i++ )
    {
        cout << translateX(i) << " ";
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

    #ifdef _DEBUG  //( or #ifndef _NDEBUG )
        printVector(gridlength, width, height);
    #endif

    delVector();
    return 0;
}
