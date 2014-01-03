#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <thread>
#include <mutex>

using namespace std;

int checkInput();
void initVector(vector<bool> &grid, int gridsize);
void initForbidden(vector<bool> &grid, int gridsize, int height, int width);
void printVector(vector<bool> &grid, int gridsize, int width, int height);
void takeStep(vector<bool> &grid, vector<unsigned short> &number, int width, int height, int rest, int pos, int Y, bool firstit = false);
int main();

#endif // MAIN_HPP_INCLUDED
