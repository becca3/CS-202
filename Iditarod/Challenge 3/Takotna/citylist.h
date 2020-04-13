#ifndef CITYLIST_H_
#define CITYLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "CityNode.h"

class Citylist
{
public:
    //Default Constructor
    Citylist();

    //Constructor adding node to _cityList vector
    Citylist(CityNode node);

    //Adds node to _cityList vector
    void setCityNode(CityNode node);

    //Prints whole _cityList vector
    void printCityNodes();

    /*Prints specific vector position of _cityList depending
      on node you want printed*/
    void printSpecificCityNode(unsigned int node);

    //Sets file/city name
    void setFileName(std::string name);

    //returns _fileName
    std::string getFileName();

    //Returns Euclidean distance between two cities.
    double distance(int first, int second);

    //returns _nodeNumber from CityNode
    unsigned int getCityNode(int node);

    //returns  _latitude from CityNode
    double getCityLat(int node);

    //returns _longitude from CityNode
    double getCityLon(int node);

    int citylistSize();

private:
    std::vector<CityNode> _cityList;
    std::string _fileName;
    CityNode node;
};

#endif