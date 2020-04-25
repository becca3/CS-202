#include "svg.h"
using std::istringstream;

void graphSVG(Citylist& list, Citypath& path, std::string outName) 
{
    double minX = list.Xmin();
    double maxX = list.Xmax();
    double minY = list.Ymin();
    double maxY = list.Ymax();

    std::string line;

    std::ofstream svgOut(outName);
    if (svgOut.is_open())
    {
        line = "<html xmlns=\"http://www.w3.org/1999/xhtml\"\n";
        line += "xmlns:svg=\"http://www.w3.org/2000/svg\">\n";
        line += "<body>\n <svg:svg width=\"2250px\" height=\"2500px\">\n";
        
        svgOut << line;

        double x = 0;
        double y = 0;
        double oldX = 0;
        double oldY = 0;
        double startX = 0;
        double startY = 0;
        std::string dot = "";

        for (auto i = 0; i < path.size(); i++) {
            oldX = x;
            oldY = y;

            dot = "<svg:circle cx=\"";
            x = 1980 - 1920 * (list.getCityLon(path.Getpath(i)) - minX) / (maxX - minX);
            y = 2080 - 1080 * (list.getCityLat(path.Getpath(i)) - minY) / (maxY - minY);

            //Cities
            dot += std::to_string(x);
            dot += "\" cy=\"";
            dot += std::to_string(y);
            dot += "\" r=\"";
            dot += '3';
            dot += "\" fill=\"#0078ff\"/>\n";

            if (i == 0) {
                startX = x;
                startY = y;
            }

            //Lines
            if (i != 0)
            {
                dot += "<svg:line x1=\"";
                dot += std::to_string(oldX);
                dot += "\" y1=\"";
                dot += std::to_string(oldY);
                dot += "\" x2=\"";
                dot += std::to_string(x);
                dot += "\" y2=\"";
                dot += std::to_string(y);
                dot += "\" style=\"stroke:rgb(255,0,0);stroke-width:1\" />\n";
            }


            svgOut << dot;
        }

        //Connect last city to first
        dot = "<svg:line x1=\"";
        dot += std::to_string(x);
        dot += "\" y1=\"";
        dot += std::to_string(y);
        dot += "\" x2=\"";
        dot += std::to_string(startX);
        dot += "\" y2=\"";
        dot += std::to_string(startY);
        dot += "\" style=\"stroke:rgb(255,0,0);stroke-width:1\" />\n";


        line = "</svg:svg>\n <svg:svg width=\"2250px\" height=\"2500px\">\n";
        line += "</svg:svg>\n </body>\n </html>";
        svgOut << line;
    }
}

void readfile(std::string fileName, CityNode& node, Citylist& city)
{
    std::ifstream ifile(fileName);
 
    if (!ifile)
    {
        std::cout << "Couldn't open file." << std::endl;
    }
    else
    {
        city.setFileName(fileName);
        std::string line;
        bool loop = true;

        while (loop)
        {
            //EOF
            if (!ifile)
            {
                if (ifile.eof())
                {
                    loop = false;
                }
                else
                {
                    loop = true;
                }
            }
            //No EOF.
            else
            {
                getline(ifile, line);
                std::string nodeStart = "NODE_COORD_SECTION";

                //Start listings
                if (line == nodeStart)
                {
                    bool loop1 = true;
                    while (loop1)
                    {
                        if (line == "EOF")
                        {
                            loop1 = false;
                            loop = false;
                        }
                        else
                        {
                            loop1 = true;
                        }
                        getline(ifile, line);

                        istringstream iss(line);
                        int val;
                        iss >> val;
                        if (iss)
                        {
                            istringstream iss1(line);
                            //Grab each section of string
                            for (int i = 0; i < 3; i++)
                            {
                                double val1;

                                iss1 >> val1;
                                //Node number
                                if (i == 0)
                                {
                                    node.setNodeNo(val1);
                                }
                                //Latitude
                                else if (i == 1)
                                {
                                    node.setYLatitude(val1);
                                }
                                //Longitude
                                else if (i == 2)
                                {
                                    node.setXlongitude(val1);
                                }
                            }
                            city.setCityNode(node);
                        }
                    }
                }
            }
        }
    }
}