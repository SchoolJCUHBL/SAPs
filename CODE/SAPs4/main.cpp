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
/*
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
*/

void takeStep(vector<bool> &grid, vector<unsigned short> &number, int width, int height, int rest, int pos, int Y, bool firstit)
{
    if (grid.at(pos) == false)
    {
        grid.at(pos) = true;
        div_t xyresult = div(pos, width);
        int DeltaPos = abs(xyresult.quot-Y) + abs(xyresult.rem-1);
        if (DeltaPos <= rest)
        {
            if (rest == 1 && rest == DeltaPos)
            {
                add(number);
            }
            else
            {
                signed int directions[] = {1,width,-1,-width};

                if (firstit)
                {
                    //kloon de vector 3x zodat er 4 vectoren zijn. 1 zal al snel klaar zijn
                    cout << "Initializing Worker Resouces" << endl;

                    vector<vector<bool>> threadedgrids (4, grid);
                    vector<vector<unsigned short>> counters (4, number);
                    vector<thread> threads;

                    cout << "Done" << endl << endl << "Starting Workers" << endl;

                    for (int i = 0; i < 4; i++)
                    {
                        threads.emplace_back(thread(takeStep, ref(threadedgrids.at(i)), ref(counters.at(i)), width, height, rest-1, pos+directions[i], Y, 0));
                    }
                    cout << "Workers Started" << endl << endl;

                    for(auto& thread : threads)
                    {
                        cout << "Worker Finished" << endl;

                        thread.join();
                    }
                    cout << endl << "All Workers Finished!" << endl << endl;
                    cout << "Calculating result" << endl << endl;

                    finalize(number, counters);
                }
                else
                {
                    for (int &i: directions)
                    {
                        takeStep(grid, number, width, height, rest-1, pos+i, Y);
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

    int width = (SAPlength/2)+2;
    int height = SAPlength+1;
    int gridlength = height*width;

    initVector(grid0, gridlength);
    initForbidden(grid0, gridlength, height, width);

    int Y = translateYtoMachine(0, height);
    int startpos = Y * width + 1;
    grid0.at(startpos) = true;

    takeStep(grid0, number, width, height, SAPlength-1, startpos+1, Y, true);

    //printVector(grid0, gridlength, width, height);
    printCount(number);

    return 0;
}
