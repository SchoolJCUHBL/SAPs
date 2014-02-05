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

vector<unsigned short> takeStep(vector<bool> grid, int width, int height, int rest, int pos, int Y, int depth)
{
    vector<unsigned short> number (1, 0);
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
                signed int directions[4] = {1,width,-1,-width}; //makes an array with four values, representing the values that need to be added to pos to go up, right, down, left.

                vector<future<vector<unsigned short>>> futures;

                for (int i = 0; i < 4; i++)
                {
                    futures.push_back(async(launch::async, takeStep, grid, width, height, rest-1, pos+directions[i], Y, depth+1)); //make new threads, each executing takestep
                }

                vector<vector<unsigned short>> counters;

                for(auto &e : futures) {
                    counters.push_back(e.get());
                }
                finalize(number, counters); //calculate total number of SAP's found by the worker threads
            }
        }
        grid.at(pos) = false;
    }
    return number;
}

int main(int argc,char *argv[])
{
    ofstream outputFile;
    outputFile.open("SAPsLog.txt", ios::out | ios::app);

    int SAPlength = 0;

    if (outputFile.is_open())
    {
        if (argc <= 1)
        {
            SAPlength = checkInput();
            cout << "SAP length is: " << SAPlength << endl << endl;
        }
        else
        {
            istringstream ss(argv[1]);
            int x;
            if (!(ss >> x))
            {
                SAPlength = checkInput();
                cout << "SAP length is: " << SAPlength << endl << endl;
            }
            else
            {
                SAPlength = x;
            }
        }

        outputFile << "start IT" << endl;
        vector<bool> grid0;

        int width = (SAPlength/2)+2; //the size of the grid depends on the SAP-length
        int height = SAPlength+1;
        int gridlength = height*width; //the vector is 1D, but interpreted as 2D

        initVector(grid0, gridlength);
        initForbidden(grid0, gridlength, height, width);

        int Y = translateYtoMachine(0, height);
        int startpos = Y * width + 1;
        grid0.at(startpos) = true;

        //cout << "start" << endl;

        vector<unsigned short> number = takeStep(grid0, width, height, SAPlength-1, startpos+1, Y); //take the first step

        //printVector(grid0, gridlength, width, height);
        outputFile << "result: ";
        outputFile << printCount(number) <<" " << endl;
    }
    outputFile << endl;
    outputFile.close();
    return 0;
}
