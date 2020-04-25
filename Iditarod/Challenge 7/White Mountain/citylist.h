#ifndef CITYLIST_H
#define CITYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "CityNode.h"

class Citylist
{
public:
    //Default Constructor.
    Citylist();

    //Constructor adding node to citylist vector.
    Citylist(CityNode node);

    //Adds node to citylist vector.
    void setCityNode(CityNode node);

    //Prints whole _cityList vector.
    void printCityNodes();

    void printSpecificCityNode(unsigned int node);

    //Sets file/city name.
    void setFileName(std::string name);

    std::string getFileName();

    //Returns Euclidean distance between two cities.
    double distance(int first, int second);

    //Returns nodeNumber.
    CityNode getCityNode(int node);

    //Returns  latitude.
    double getCityLat(int node);

    //Returns longitude.
    double getCityLon(int node);

    int citylistSize();

    int listVectorSpecific(int n);

    int getCityNodeInteger(int node);

    void removeCityList(int node);

    double Xmin();

    double Xmax();

    double Ymin();

    double Ymax();

private:

    std::vector<CityNode> _cityList;
    std::string _fileName;
    CityNode node;
};

#endif