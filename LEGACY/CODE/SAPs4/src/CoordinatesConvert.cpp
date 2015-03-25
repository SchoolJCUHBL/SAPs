#include "CoordinatesConvert.h"

int translateXtoMan(int X)
{
    return --X;
}

int translateXtoMachine(int X)
{
    return ++X;
}

int translateYtoMan(int Y, int height)
{
    return height-Y-((height)/2)-1;
}

int translateYtoMachine(int Y, int height)
{
    return (height/2)-Y;
}
