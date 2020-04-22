#include "citylist.h"

Citylist::Citylist() 
{

}

Citylist::Citylist(CityNode node)
{
    _cityList.push_back(node);
}

void Citylist::setCityNode(CityNode node)
{
    _cityList.push_back(node);
}

CityNode Citylist::getCityNode(int node)
{
    return _cityList[node];
}

double Citylist::getCityLat(int node)
{
    return _cityList[node].getYLatitude();
}

double Citylist::getCityLon(int node)
{
    return _cityList[node].getXLongitude();
}

//Function to print city nodes.
void Citylist::printCityNodes()
{
    for (auto a : _cityList)
    {
        std::cout << "City: " << getFileName() << " Node: " << a.getNodeNo()
            << " Lattitude: " << a.getYLatitude() << " Longitude: " << a.getXLongitude()
            << std::endl;
    }
}

//Function to print only a specific node. 
void Citylist::printSpecificCityNode(unsigned int node)
{
    std::cout << "City: " << getFileName() << " Node: "
        << _cityList[node - 1].getNodeNo() << " Lattitude: "
        << _cityList[node - 1].getYLatitude() << " Longitude: "
        << _cityList[node - 1].getXLongitude() << std::endl;
}

//Function sets file name.
void Citylist::setFileName(std::string name)
{
    _fileName = name;
}

std::string Citylist::getFileName()
{
    return _fileName;
}

//Returns Euclidean distance between two cities.
double Citylist::distance(int first, int second)
{
    //x = long y = lat.
    double a, x1, x2, y1, y2;
    x1 = getCityLon(first);
    x2 = getCityLon(second);
    y1 = getCityLat(first);
    y2 = getCityLat(second);

    a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return a;
}

int Citylist::citylistSize()
{
    return _cityList.size();
}

int Citylist::listVectorSpecific(int n)
{
    return _cityList[n].getNodeNo();
}

void Citylist::removeCityList(int node)
{
    _cityList.erase(_cityList.begin() + node);
}