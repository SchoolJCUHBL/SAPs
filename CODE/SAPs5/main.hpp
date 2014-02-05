#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <sstream>
#include <future>

using namespace std;

int checkInput();
void initVector(vector<bool> &grid, int gridsize);
void initForbidden(vector<bool> &grid, int gridsize, int height, int width);
void printVector(vector<bool> &grid, int gridsize, int width, int height);
vector<unsigned short> takeStep(vector<bool> grid, int width, int height, int rest, int pos, int Y, int depth = 0);
int main(int argc,char *argv[]);

#endif // MAIN_HPP_INCLUDED
