#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <thread>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::int256_t;

int checkInput();
void initVector(vector<bool> &grid, int gridsize);
void initForbidden(vector<bool> &grid, int gridsize, int height, int width);
void printVector(vector<bool> &grid, int gridsize, int width, int height);
void ConvertStep(vector<bool> grid, int256_t &number, int width, int height, int rest, int pos, int Y);
void takeFirstStep(vector<bool> &grid, int256_t &number, int width, int height, int rest, int pos, int Y);
void takeStep(vector<bool> &grid, int256_t &number, int width, int height, int rest, int pos, int Y);
int main(int argc,char *argv[]);

#endif // MAIN_HPP_INCLUDED
