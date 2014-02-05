#include "version.h"
#include "main.hpp"
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
    int j = 0;
    cout << endl;
    for (int i = 0; i < (gridsize) ;i++ )
    {
        if (i%width == 0)
        {
            cout << endl << setw(3) << j++ << " | " << setw(3) << translateYtoMan(j, height) << "\t";
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
void ConvertStep(vector<bool> grid, int256_t &number, int width, int height, int rest, int pos, int Y)
{
    takeStep(grid, number, width, height, rest, pos, Y);
}

void takeFirstStep(vector<bool> &grid,int256_t &number, int width, int height, int rest, int pos, int Y)
{
    if (!grid.at(pos))
    {
        grid.at(pos) = true;
        //kloon de vector 3x zodat er 4 vectoren zijn. 1 zal al snel klaar zijn

        vector<int256_t> counters (8, 0);
        vector<thread> threads;

        signed int directions[] = {1,width,-1,-width};

        int indexer = 0;

        for (int i = 0; i < 4; i++ )
        {
            int temppos = pos;
            temppos += directions[i];
            if (!grid.at(temppos))
            {
                grid.at(temppos) = true;
                for (int j = 0; j < 4; j++)
                {
                    int temppos2 = temppos;
                    temppos2 += directions[j];
                    if (!grid.at(temppos2) && temppos2 != (Y*width + 1 + width))
                    {
                        threads.emplace_back(thread(ConvertStep, grid, ref(counters.at(indexer)), width, height, rest-2, temppos2, Y));
                        indexer++;
                    }
                }
                grid.at(temppos) = false;
            }
        }

        for(auto& thread : threads)
        {
            thread.join();
        }

        for (int i = 0; i < 8; i++)
        {
            number = number + counters.at(i);
        }
        grid.at(pos) = false;
    }

}

void takeStep(vector<bool> &grid, int256_t &number, int width, int height, int rest, int pos, int Y)
{
    if (!grid.at(pos))
    {
        grid.at(pos) = true;
        div_t xyresult = div(pos, width);
        int DeltaPos = abs(xyresult.quot-Y) + abs(xyresult.rem-1);
        if (DeltaPos <= rest)
        {
            if (DeltaPos == 1)
            {
                if (rest == 1)
                {
                    number = number + 1;
                }
            }
            else
            {
                signed int directions[] = {1,width,-1,-width};

                for (int &i: directions)
                {
                    takeStep(grid, number, width, height, rest-1, pos+i, Y);
                }
            }

        }
        grid.at(pos) = false;
    }
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

        vector<bool> grid;

        int256_t number = 0;

        int width = (SAPlength/2)+2;
        int height = SAPlength+1;
        int gridlength = height*width;

        initVector(grid, gridlength);
        initForbidden(grid, gridlength, height, width);

        int Y = translateYtoMachine(0, height);
        int startpos = Y * width + 1;
        grid.at(startpos) = true;

        takeFirstStep(grid, number, width, height, SAPlength-1, startpos+1, Y);

        //printVector(grid, gridlength, width, height);
        outputFile << "result L" << SAPlength << ": " << number << ";" << endl;
    }
    outputFile.close();
    return 0;
}
