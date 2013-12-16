//included libs
#include <iostream>
#include <vector>
#include "SAP.h"

using namespace std;

//function main starts the execution

SAP::SAP(vector<int> x, vector<int> y, int rest)
{
    // geef properties waardes
    locXs = x;
    locYs = y;
    n = rest;
    //ctor
}

void SAP::takeStep()
{

}

SAP::~SAP()
{
    //dtor
}
