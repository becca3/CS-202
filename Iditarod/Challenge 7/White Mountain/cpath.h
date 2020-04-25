#ifndef CPATH_H
#define CPATH_H

#include <iostream>
#include <vector>

#include "CityNode.h"

class Citypath
{
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

    std::vector<int> connections_;

    int _size;
};

#endif

