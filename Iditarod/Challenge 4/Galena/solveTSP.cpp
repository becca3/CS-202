#include "solveTSP.h"

unsigned int TSPSolver::getRandomInt(int low, int high)
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
    //Set starting city.
    int high = list.citylistSize();
    int startNode = getRandomInt(0, high);
    path.setCityPath(list.getCityNode(startNode));

    int totalDist = 0;
    
    int cityPathNumber = 1;
    while (cityPathNumber != list.citylistSize())
    {
        int n = path.cpathSize() - 1;

        //list.removeCityList(n);
        
        int bestDist = 1e12;
        for (int i = 0; i < list.citylistSize(); i++)
        {
            int dist = list.distance(path.pathVectorSpecific(n),
                list.listVectorSpecific(i));
            std::cout << dist << " traveled.\n";

            if (dist < bestDist)
            {
                if (path.cpathSize() != cityPathNumber)
                {
                    path.BackPath();
                }
                bestDist = dist;
                path.setCityPath(list.getCityNode(i));
            }
        }
        totalDist += bestDist;
        cityPathNumber++;

    }

    std::cout << "Solve Greedy contains " << path.cpathSize() << " cities.\n"
        << "Total distance traveled: " << totalDist << std::endl;
    path.printCityPath();

}