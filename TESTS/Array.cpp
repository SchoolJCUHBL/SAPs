//included libs
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;

int input(istream& in=cin)
{
	int x;
	in >> x;
	return x;
}

//function main starts the execution
int main()
{
    int X;

    cout << "Square fields: ";
    cin >> X;

	int board[X][X]; //creates a 9*9 matrix or a 2d array.

	for(int i=0; i<X; i++)    //This loops on the rows.
	{
		for(int j=0; j<X; j++) //This loops on the columns
		{
			board[i][j] = 0;          //input(); //you can also connect to the file
			//and place the name of your ifstream in the input after opening the file will
			//let you read from the file.
		}
	}

	for(int i=0; i<X; i++)    //This loops on the rows.
	{
		for(int j=0; j<X; j++) //This loops on the columns
		{
			cout << board[i][j]  << "  ";
		}
		cout << endl;
	}
	return 0;
}
