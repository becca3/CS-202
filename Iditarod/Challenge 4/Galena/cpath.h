#ifndef CPATH_H_
#define CPATH_H_

#include <iostream>
#include <vector>

#include "CityNode.h"

class Citypath
{
public:
    //Default Constructor.
    Citypath();

    Citypath(CityNode node);

    //Adds node to citylist vector.
    void setCityPath(CityNode node);

    //Prints connections to terminal.
    void printCityPath();

    int cpathSize();

    int pathVectorSpecific(int n);

    void BackPath();

private:
    std::vector<int> connections_;
};

#endif

