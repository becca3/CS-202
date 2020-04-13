#include "cpath.h"

Citypath::Citypath() {}

Citypath::Citypath(CityNode node)
{
    int connection = node.getNodeNo();
    connections_.push_back(connection);
}

void Citypath::setCityPath(CityNode node)
{
    int connection = node.getNodeNo();
    connections_.push_back(connection);
}

void Citypath::printCityPath()
{
    for (auto a : connections_)
    {
        std::cout << a << std::endl;
    }
}