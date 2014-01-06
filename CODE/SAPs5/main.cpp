#include "version.h"
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
    for (int i = 0; i < (gridsize); i++) //sets entire grid to false
    {
        grid.push_back (false);
    }
}

void initForbidden(vector<bool> &grid, int gridsize, int height, int width) //sets certain areas to true, meaning the SAP can't go there
{
    for (int i = 0; i < width; i++) //sets left and right border to true
    {
        grid.at(i) = true;
        grid.at(gridsize - width + i) = true;
    }
    for (int i = 0; i < height; i++) //sets top and bottom border to true
    {
        grid.at(width * i) = true;
        grid.at(width * i + (width - 1)) = true;
    }
    for (int i = 0; i < height/2; i++) //sets area above starting point to true
    {
        grid.at(width * i + 1) = true;
    }
}
/*
void printVector(vector<bool> &grid, int gridsize, int width, int height) //prints the grid to the console, for debug purposes
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
*/

void takeStep(vector<bool> &grid, vector<unsigned short> &number, int width, int height, int rest, int pos, int Y, int depth)
{
    if (grid.at(pos) == false) //only if the point that has just been entered is legal (false) will the code continue. if the point is true, the function will do nothing.
    {
        grid.at(pos) = true;
        div_t xyresult = div(pos, width);
        int DeltaPos = abs(xyresult.quot-Y) + abs(xyresult.rem-1);
        if (DeltaPos <= rest) //the number of steps needed to "go home" is equal to the sum of the absolute values of the coordinates. if that is less than the number of available steps, the SAP can't go home and thus doesn't qualify
        {
            if (rest == 1 && rest == DeltaPos) //if the SAP can only take one more step, and has only one to take, he is technically home, so the number of SAP's increases by one.
            {
                add(number);
            }
            else
            {
                signed int directions[] = {1,width,-1,-width}; //makes an array with four values, representing the values that need to be added to pos to go up, right, down, left.

                if (depth == 0 || depth == 1 || depth == 2 || depth == 3/* || depth == 4 || depth == 5*/) //The depths on which the program will spawn threads
                {
                    //kloon de vector 4x zodat er 4 vectoren zijn. 1 zal al snel klaar zijn
                    vector<vector<bool>> threadedgrids (4, grid);
                    vector<vector<unsigned short>> counters (4, vector<unsigned short> (1, 0));
                    vector<thread> threads;

                    for (int i = 0; i < 4; i++)
                    {
                        threads.emplace_back(thread(takeStep, ref(threadedgrids.at(i)), ref(counters.at(i)), width, height, rest-1, pos+directions[i], Y, depth+1)); //make new threads, each executing takestep
                    }

                    for(auto& thread : threads)
                    {
                        thread.join(); //wait for each thread to finish
                    }

                    finalize(number, counters); //calculate total number of SAP's found by the worker threads
                }
                else
                {
                    for (int &i: directions)
                    {
                        takeStep(grid, number, width, height, rest-1, pos+i, Y, depth+1); //this is a recursive function, with each iteration starting four more, each going in a new direction and being one shorter
                    }
                }
            }
        }
        grid.at(pos) = false;
    }
}

int main()
{
    vector<bool> grid0;
    vector<unsigned short> number (1, 0);

    int SAPlength = checkInput();
    cout << "SAP length is: " << SAPlength << endl << endl;

    int width = (SAPlength/2)+2; //the size of the grid depends on the SAP-length
    int height = SAPlength+1;
    int gridlength = height*width; //the vector is 1D, but interpreted as 2D

    initVector(grid0, gridlength);
    initForbidden(grid0, gridlength, height, width);

    int Y = translateYtoMachine(0, height);
    int startpos = Y * width + 1;
    grid0.at(startpos) = true;

    takeStep(grid0, number, width, height, SAPlength-1, startpos+1, Y); //take the first step

    //printVector(grid0, gridlength, width, height);
    printCount(number);

    return 0;
}
