#ifndef CITYLIST_H_
#define CITYLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include "CityNode.h"
#include <cmath>

class Citylist
{
public:
    //Default Constructor
    Citylist();

    //Constructor automatically adding node to _cityList vector
    Citylist(CityNode node);

    //Adds node to _cityList vector
    void setCityNode(CityNode node);

    //Prints whole _cityList vector
    void printCityNodes();

    /*Prints specific vector position of _cityList depending
      on node you want printed*/
    void printSpecCityNode(unsigned int node);

    //Sets file/city name
    void setFileName(std::string name);

    //returns _fileName
    std::string getFileName();

    //Returns Euclidean distance between two cities (node 1 & node 2).
    double distance(int first, int second);

    //returns _nodeNumber from CityNode
    unsigned int getCityNode(int node);

    //returns  _latitude from CityNode
    double getCityLat(int node);

    //returns _longitude from CityNode
    double getCityLon(int node);

private:
    std::vector<CityNode> _cityList;
    std::string _fileName;
    CityNode node;
};

#endif