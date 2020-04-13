#ifndef SOLVETSP_H_
#define SOLVETSP_H_

#include "citylist.h"
#include "cpath.h"
#include "CityNode.h"

#include <random>

class TSPSolver
{
public:
    void SolveRandomly();
    void SolveGreedy(Citylist &list, Citypath &path);
    void SolveMyWay();
    unsigned int getRandomInt(int low, int high);

private:

};

#endif