#ifndef SOLVETSP_H
#define SOLVETSP_H

#include "citylist.h"
#include "cpath.h"
#include "CityNode.h"
#include "fltk.h"

#include <random>

class TSPSolver
{
public:
    double SolveRandomly(Citylist &list, Citypath& path);
    double SolveGreedy(Citylist& list, Citypath& path);
    double SolveMyWay(Citylist &list, Citypath& path);
    unsigned int getRandomInt(int low, int high);
};

#endif