#include "cpath.h"

Citypath::Citypath(const int &b) : _size(b) {}

int Citypath::citypathSize()
{
    return connections_.size();
}

void Citypath::Addpath(const int& n)
{
    connections_.push_back(n);
}

void Citypath::Deletepath(const int& n)
{
    if (connections_.size() == 1) {
        connections_.erase(connections_.begin());
        return;
    }
    connections_.erase(connections_.begin() + n);
}

void Citypath::DeleteallPaths()
{
    connections_.clear();
}

int Citypath::Getpath(const int& n) const
{
    return connections_[n];
}

std::vector<int> Citypath::get_connections()
{
    return connections_;
}

void Citypath::Setconnections(std::vector<int>& vec)
{
    for (auto a : vec)
    {
        connections_.push_back(a);
    }
}