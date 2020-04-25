#ifndef SVG_H
#define SVG_H

#include <fstream>
#include <sstream>

using std::ofstream;
using std::ifstream;
using std::istringstream;

#include "citylist.h"
#include "cpath.h"

void graphSVG(Citylist& list, Citypath& path, std::string outName);
void readfile(std::string fileName, CityNode& node, Citylist& city);

#endif