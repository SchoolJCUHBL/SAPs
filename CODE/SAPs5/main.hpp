#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <thread>
#include <exception>
#include <stdexcept>

using namespace std;

void handle_eptr(exception_ptr eptr);
int checkInput();
void initVector(vector<bool> &grid, int gridsize);
void initForbidden(vector<bool> &grid, int gridsize, int height, int width);
void printVector(vector<bool> &grid, int gridsize, int width, int height);
void takeStep(vector<bool> &grid, vector<unsigned short> &number, int width, int height, int rest, int pos, int Y, int depth = 0);
int main();

#endif // MAIN_HPP_INCLUDED
