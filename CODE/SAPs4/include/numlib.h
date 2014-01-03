#ifndef NUMLIB_H_INCLUDED
#define NUMLIB_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <mutex>

using namespace std;

void printCount (vector<unsigned short> &number);
void correct (vector<unsigned short> &number, int position = 0, int system = 10);
void add (vector<unsigned short> &number, int addition = 1);
void finalize (vector<unsigned short> &number, vector<vector<unsigned short>> &counters);

#endif // NUMLIB_H_included
