#include "solveTSP.h"
#include "citylist.h"

unsigned int TSPSolver::getRandomInt(int low, int high)
{
    std::random_device rd;
    std::mt19937 gen1(rd());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(gen1);
}

void TSPSolver::SolveRandomly(Citylist& list, Citypath& marked)
{
    Citypath unmarked;
    std::vector<int> temp;
    std::vector<int> finalVec;

    //Starting distance
    double dist = 0;

    //Best Distance
    double bestDist = 1e12;

    //M times repeated -- Change m to whatever
    int m = 100;

    for (int i = 0; i < m; i++)
    {
        temp.clear();
        dist = 0;
        unmarked.DeleteallPaths();
        //Fill unmarked path
        for (int i = 0; i < list.citylistSize(); i++)
        {
            unmarked.Addpath(i);
        }
        temp.clear();
        //Set starting city
        int startNode = getRandomInt(0, list.citylistSize() - 1);
        //Add starting city to temp
        temp.push_back(startNode);
        //Delete starting city from unmarked
        unmarked.Deletepath(startNode);

        //While cities unmarked remain
        while (unmarked.size() != 0)
        {
            //Randomly connect cities
            int startNode = getRandomInt(0, unmarked.size() - 1);
            temp.push_back(unmarked.Getpath(startNode));
            unmarked.Deletepath(startNode);
        }

        //Starting city is also ending city
        temp.push_back(temp[0]);

        //Find distance traveled
        for (auto i = 0; i < temp.size() - 1; i++)
        {
            dist += list.distance(temp[i], temp[i + 1]);
        }

        if (dist < bestDist)
        {
            bestDist = dist;
            finalVec = temp;
        }
    }

    marked.Setconnections(finalVec);
    dist = 0;
    //cout << "Path traveled: ";
    for (int i = 0; i < marked.size() - 1; i++)
    {
        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
        //cout << marked.getPath(i) << " ";
    }
    //cout << marked.getPath(marked.size() - 1) << endl;
    std::cout << "Total distance: " << dist << std::endl;
}

void TSPSolver::SolveGreedy(Citylist& list, Citypath& marked)
{
    Citypath unmarked;

    //Fill unmarked path
    for (int i = 0; i < list.citylistSize(); i++)
    {
        unmarked.Addpath(i);
    }

    //Starting distance
    double dist = 0;

    //Set starting city
    int startNode = getRandomInt(0, list.citylistSize() - 1);
    //Add starting city to marked
    marked.Addpath(startNode);
    //Delete starting city from unmarked
    unmarked.Deletepath(startNode);

    int smallest;
    int del;
    // Loop for all nodes
    for (int i = 0; i < list.citylistSize(); i++)
    {
        dist = 1e12;

        //If last city
        if (unmarked.size() == 1)
        {
            marked.Addpath(unmarked.Getpath(0));
            unmarked.Deletepath(0);
            break;
        }

        //Find closest city comparing all cities remaining (unmarked)
        for (auto z = 0; z < unmarked.citypathSize(); z++)
        {
            if (dist > list.distance(marked.Getpath(i), unmarked.Getpath(z)))
            {
                dist = list.distance(marked.Getpath(i), unmarked.Getpath(z));

                //Smallest city found
                smallest = unmarked.Getpath(z);
                //Delete the found city
                del = z;
            }
        }

        marked.Addpath(smallest);
        unmarked.Deletepath(del);

    }

    marked.Addpath(marked.Getpath(0));

    dist = 0;
    //cout << "Path traveled: ";
    for (int i = 0; i < marked.size() - 1; i++)
    {
        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
        //cout << marked.getPath(i) << " ";
    }
    //cout << marked.getPath(marked.size() - 1) << endl;
    std::cout << "Total distance: " << dist << std::endl;
}

void TSPSolver::SolveMyWay(Citylist& list, Citypath& marked)
{
    // Connect cities in node order (ending with starting node)

    for (int i = 0; i < list.citylistSize(); i++)
    {
        marked.Addpath(i);
    }

    int dist = 0;
    //cout << "Path traveled: ";
    for (int i = 0; i < marked.size() - 1; i++)
    {
        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
        //cout << marked.getPath(i) << " ";
    }
    //cout << marked.getPath(marked.size() - 1) << endl;
    std::cout << "Total distance: " << dist << std::endl;

}

//unsigned int TSPSolver::getRandomInt(int low, int high)
//{
//    std::random_device rd;
//    std::mt19937 gen1(rd());
//    std::uniform_int_distribution<int> dist(low, high);
//    return dist(gen1);
//}
//
//void TSPSolver::SolveRandomly(Citylist &list, Citypath& path)
//{
//    Citypath marked;
//    Citypath unmarked;
//    std::vector<int> holder;
//    std::vector<int> final;
//
//    double dist = 0;
//
//    //Best Distance
//    double bestDist = 1e12;
//
//    int m = 10;
//
//    for (int x = 0; x < m; x++)
//    {
//        holder.clear();
//        dist = 0;
//        unmarked.DeleteallPaths();
//   
//        for (int i = 0; i < list.citylistSize(); i++)
//        {
//            unmarked.Addpath(i);
//        }
//        
//        holder.clear();
//
//        //Starting city.
//        int startNode = getRandomInt(0, list.citylistSize() - 1);
//
//        //Add city to holder.
//        holder.push_back(startNode);
//
//        unmarked.Deletepath(startNode);
//
//        //While cities unmarked remain
//        while (unmarked.size() != 0)
//        {
//            int startNode = getRandomInt(0, unmarked.size() - 1);
//            holder.push_back(unmarked.Getpath(startNode));
//            unmarked.Deletepath(startNode);
//        }
//
//        //Starting city is also ending city
//        holder.push_back(holder[0]);
//
//        //Find distance traveled
//        for (auto i = 0; i < holder.size() - 1; i++)
//        {
//            dist += list.distance(holder[i], holder[i + 1]);
//        }
//
//        if (dist < bestDist)
//        {
//            bestDist = dist;
//            final = holder;
//        }
//    }
//
//    marked.Setconnections(final);
//    dist = 0;
//    std::cout << "Path traveled: ";
//    for (int i = 0; i < marked.size() - 1; i++)
//    {
//        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
//        std::cout << marked.Getpath(i) << " ";
//    }
//    std::cout << marked.Getpath(marked.size() - 1) << std::endl;
//    std::cout << "Total distance: " << dist << std::endl;
//}
//
//void TSPSolver::SolveGreedy(Citylist& list, Citypath& path)
//{
//    //Citypath marked;
//    Citypath unmarked;
//
//    for (int i = 0; i < list.citylistSize(); i++)
//    {
//        unmarked.Addpath(i);
//    }
//
//    //Starting distance.
//    double dist = 0;
//
//    //Starting city.
//    int startNode = getRandomInt(0, list.citylistSize() - 1);
//
//    marked.Addpath(startNode);
//
//    unmarked.Deletepath(startNode);
//
//    int small;
//    int del;
//
//    for (int i = 0; i < list.citylistSize(); i++)
//    {
//        dist = 1e12;
//
//        //Last city.
//        if (unmarked.size() == 1)
//        {
//            marked.Addpath(unmarked.Getpath(0));
//            unmarked.Deletepath(0);
//            break;
//        }
//
//        for (auto z = 0; z < unmarked.citypathSize(); z++)
//        {
//            if (dist > list.distance(marked.Getpath(i), unmarked.Getpath(z)))
//            {
//                dist = list.distance(marked.Getpath(i), unmarked.Getpath(z));
//
//                small = unmarked.Getpath(z);
//                del = z;
//            }
//        }
//
//        marked.Addpath(small);
//        unmarked.Deletepath(del);
//
//    }
//
//    marked.Addpath(marked.Getpath(0));
//
//    dist = 0;
//    std::cout << "Path traveled - ";
//    for (int i = 0; i < marked.size() - 1; i++)
//    {
//        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
//        std::cout << marked.Getpath(i) << " ";
//    }
//    std::cout << marked.Getpath(marked.size() - 1) << std::endl;
//    std::cout << "Total distance - " << dist << std::endl;
//}
//
//void TSPSolver::SolveMyWay(Citylist& list, Citypath& marked)
//{
//    // Connect cities in node order (ending with starting node)
//    //Citypath marked;
//
//    for (int i = 0; i < list.citylistSize(); i++)
//    {
//        marked.Addpath(i);
//    }
//
//    int dist = 0;
//    //std::cout << "Path traveled: ";
//    for (int i = 0; i < marked.size() - 1; i++)
//    {
//        dist += list.distance(marked.Getpath(i), marked.Getpath(i + 1));
//        //std::cout << marked.Getpath(i) << " ";
//    }
//    //std::cout << marked.Getpath(marked.size() - 1) << std::endl;
//    std::cout << "Total: " << dist << std::endl;
//
//}