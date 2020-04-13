#ifndef CPATH_H_
#define CPATH_H_

#include <iostream>
#include <vector>

#include "CityNode.h"

class Citypath
{
public:
    //Default Constructor
    Citypath();

    //Constructor automatically adding node to _connections vector
    Citypath(CityNode node);

    //Adds node to _cityList vector
    void setCityPath(CityNode node);

    //Prints _connections to terminal
    void printCityPath();


private:
    //Stores optimal connections from city to city (vector<CityNode> _cityList)
    std::vector<int> connections_;
};

#endif

