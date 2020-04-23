#include "svg.h"

void graphSVG(Citylist& list, Citypath& path, std::string outName) {
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

        // INSERT CITIES AND LINES HERE
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