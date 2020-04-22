#include "CityNode.h"

CityNode::CityNode()
{

}

CityNode::CityNode(unsigned int node, double Ylat, double Xlong)
{
	nodeNumber_ = node;
	latitude_ = Ylat;
	graphY_ = Ylat;
	longitude_ = Xlong;
	graphX_ = Xlong;
}

void CityNode::setNodeNo(unsigned int node)
{
	nodeNumber_ = node;
}

void CityNode::setYLatitude(double lat)
{
	latitude_ = lat;
	graphY_ = lat;
}

void CityNode::setXlongitude(double lon)
{
	longitude_ = lon;
	graphX_ = lon;
}

unsigned int CityNode::getNodeNo()
{
	return nodeNumber_;
}

double CityNode::getYLatitude()
{
	return latitude_;
}

double CityNode::getXLongitude()
{
	return longitude_;
}