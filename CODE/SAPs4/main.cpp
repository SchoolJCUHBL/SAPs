#include "main.hpp"

std::vector<bool> grid;

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
    for (int i = 0; i < (gridsize - 1); i++)
    {
        grid.push_back (false);
    }
}

int translateY()
{

}

int translateX()
{

}

int main()
{
    int SAPlength = checkInput();

    cout << "SAP length is: " << SAPlength << endl;

    int gridlength = ((SAPlength+1)*((SAPlength/2)+2));

    initVector(gridlength);


    return 0;
}
