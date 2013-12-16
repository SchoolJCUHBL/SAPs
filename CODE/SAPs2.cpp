//included libraries list
#include <iostream>
#include <iomanip>
#include <array>
#include <cstdio>

using namespace std;

const int square = 50;

const int ROWS = square*2+1+2;
const int COLS = square+1+2;
const int startx = 1;
const int starty = square+1;

//function Main starts the execution
int main()
{
    array<array<int, ROWS>, COLS> grid;

    int SAPlength = 0;

    //prompt user for length
    cout << "Enter the length in steps of the SAP (integer, even, larger or equal to 4) : ";
    cin  >> SAPlength;

    while ((SAPlength % 2) != 0 || SAPlength < 4) {
        cout << "Error, Wrong number! Please enter an even integer, larger or equal to 4 : ";
        cin  >> SAPlength;
    }

    cout << "SAP length is: " << SAPlength << endl;

    for(int i = 0;i < COLS; ++i){
        for(int j = 0;j < ROWS; ++j) {
            grid[i][j] = 0;
        }
    }

    grid[startx][starty] = 1;

    for(int i = 0;i < starty; ++i){
        grid[1][i] = 2;
    }

    for(int i = 0;i < ROWS; ++i){
        grid[0][i] = 2;
        grid[COLS-1][i] = 2;
    }

    for(int i = 0;i < COLS; ++i){
        grid[i][0] = 2;
        grid[i][ROWS-1] = 2;
    }

    for(int i = 0;i < ROWS; ++i){
        for(int j = 0;j < COLS; ++j){
            printf("%d ", grid[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    cout << "Program ended successfully" << endl;

    return 0;
}
