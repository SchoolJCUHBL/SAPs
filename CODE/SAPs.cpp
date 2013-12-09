//included libraries list
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//function Main starts the execution
int main()
{
    int SAPlength = 0;

    //prompt user for length
    cout << "Enter the length in steps of the SAP (integer, even, larger or equal to 4) : ";
    cin  >> SAPlength;

    while ((SAPlength % 2) != 0 || SAPlength < 4) {
        cout << "Error, Wrong number! Please enter an even integer, larger or equal to 4 : ";
        cin  >> SAPlength;
    }

    cout << "SAP length is: " << SAPlength << endl;

  vector<vector<bool> > items;
  for ( int i = 0; i < SAPlength+1; i++ ) {
    items.push_back ( vector<bool>() );
    for ( int j = 0; j < SAPlength+1; j++ )
      items[i].push_back ( false );
  }

  items[SAPlength/2][SAPlength/2] = true;

  for ( int i = 0; i < SAPlength+1; i++ ) {
    for ( int j = 0; j < SAPlength+1; j++ )
      cout<< setw ( 3 ) << items[i][j] <<' ';
    cout<<'\n';
  }

    cout << "Program ended successfully" << endl;

    return 0;
}

//left+right+up+down == SAPlength
//left <= 0,5*SAPlength-1
//right <= 0,5*SAPlength-1
//up <= 0,5*SAPlength-1
//down <= 0,5*SAPlength-1
//never the same spot within one walk
