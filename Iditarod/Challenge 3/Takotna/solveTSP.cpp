#include "solveTSP.h"

unsigned int TSPSolver::getRandInt(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen1(rd());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(gen1);
}

void TSPSolver::SolveRandomly()
{
    double bestDist = 1e12;
}

void TSPSolver::SolveGreedy(Citylist& list, Citypath& path)
{
    //Set starting city
    int high = list.citylistSize();
    int startNode = getRandInt(0, high);
    path.setCityPath(list.getCityNode(startNode));

    std::cout << "Solve Greedy contains:\n";
    path.printCityPath();

}