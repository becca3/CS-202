#ifndef SOLVETSP_H_
#define SOLVETSP_H_

#include "citylist.h"
#include "cpath.h"
#include "CityNode.h"

#include <random>

class TSPSolver
{
public:
    void SolveRandomly(Citylist &list, Citypath& path);
    void SolveGreedy(Citylist &list, Citypath& path);
    void SolveMyWay(Citylist &list, Citypath& path);
    unsigned int getRandomInt(int low, int high);

private:

};

#endif