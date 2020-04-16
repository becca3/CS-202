#ifndef CPATH_H_
#define CPATH_H_

#include <iostream>
#include <vector>

#include "CityNode.h"

class Citypath
{
public:
    //Default Constructor.
public:
    Citypath(const int& s);

    Citypath() : _size(0) {};

    int citypathSize();

    Citypath(Citypath& copy) { connections_ = copy.connections_; };

    int Getpath(const int& n) const;

    void Addpath(const int& n);

    void Deletepath(const int& n);

    void DeleteallPaths();

    int size() const { return connections_.size(); }

    std::vector<int> get_connections();

    void Setconnections(std::vector<int>& vec);

private:
    //Stores optimal connections from city to city (vector<CityNode> _cityList)
    std::vector<int> connections_;

    int _size;
};

#endif

