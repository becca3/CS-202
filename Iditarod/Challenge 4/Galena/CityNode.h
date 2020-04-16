#ifndef CITYNODE_H
#define CITYNODE_H

#include <string>

class CityNode
{
public:
	CityNode();
	CityNode(unsigned int node, double Ylat, double Xlong);

	void setNodeNo(unsigned int node);
	void setYLatitude(double lat);
	void setXlongitude(double lon);

	unsigned int getNodeNo();
	double getYLatitude();
	double getXLongitude();

private:
	unsigned int nodeNumber_;
	double latitude_;
	double longitude_;
	double graphX_;
	double graphY_;
};

#endif // !CITYNODE_H


