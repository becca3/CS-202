#ifndef SOLVETSP_H_
#define SOLVETSP_H_

#include "citylist.h"
#include "cpath.h"
#include "CityNode.h"

#include <random>

class TSPSolver
{
public:
    void SolveRandomly(Citylist &list);
    void SolveGreedy(Citylist &list);
    void SolveMyWay(Citylist &list);
    unsigned int getRandomInt(int low, int high);

private:

};

#endif