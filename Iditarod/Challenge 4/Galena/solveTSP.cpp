#include "solveTSP.h"
#include "citylist.h"

unsigned int TSPSolver::getRandomInt(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen1(rd());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(gen1);
}

void TSPSolver::SolveRandomly()
{
    Citypath marked;
    Citypath unmarked;
    std::vector<int> holder;
    std::vector<int> final;

    double dist = 0;

    //Best Distance
    double bestDist = 1e12;

    int m = 10;

    for (int x = 0; x < m; x++)
    {
        holder.clear();
        dist = 0;
        unmarked.DeleteallPaths();
   
        for (int i = 0; i < list.citylistSize(); i++)
        {
            unmarked.Addpath(i);
        }
        
        holder.clear();

        //Starting city.
        int startNode = getRandomInt(0, list.citylistSize() - 1);

        //Add city to holder.
        holder.push_back(startNode);

        unmarked.Deletepath(startNode);
    }

    std::cout << "Solve Greedy contains " << path.cpathSize() << " cities.\n"
        << "Total distance traveled: " << totalDist << std::endl;
    path.printCityPath();

}