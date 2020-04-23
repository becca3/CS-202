#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "CityNode.h"
#include "citylist.h"
#include "cpath.h"
#include "solveTSP.h"
#include "svg.h"

void readfile(std::string fileName, CityNode& node, Citylist& city)
{
    std::ifstream ifile(fileName);

    //Throw error if file cannot be opened.
    if (!ifile)
    {
        std::cout << "Couldn't open file. Try again." << std::endl;
    }
    //If file opens do this.
    else
    {
        city.setFileName(fileName);
        std::string line;
        bool loop = true;

        while (loop)
        {
            //If when reading, the file hits an error or EOF (end of file).
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

            //If file opens correctly.
            else
            {
                getline(ifile, line);
                std::string nodeStart = "NODE_COORD_SECTION";

                //Start node listing
                if (line == nodeStart)
                {
                    bool loop1 = true;
                    while (loop1)
                    {
                        //If when reading, file hits EOF (end of file).
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

                        //Ensure line is an int.
                        std::istringstream iss(line);
                        int val;
                        iss >> val;

                        if (iss)
                        {
                            std::istringstream iss1(line);
                            for (int i = 0; i < 3; i++)
                            {
                                double value;
                                iss1 >> value;

                                //Node No.
                                if (i == 0)
                                {
                                    node.setNodeNo(value);
                                }

                                //Latitude.
                                else if (i == 1)
                                {
                                    node.setYLatitude(value);
                                }

                                //Longitude.
                                else if (i == 2)
                                {
                                    node.setXlongitude(value);
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

int main(int argc, char** argv)
{
    CityNode node0(0, 0, 0);
    TSPSolver solve;

    //Make CityList for BRD14051
    std::cout << "CITY: BRD14051\n";
    Citylist brd;
    readfile("brd14051.tsp", node0, brd);
    Citypath svgbrd;
    solve.SolveGreedy(brd, svgbrd);
    std::cout << "Generating Greedy SVG Output\n";
    graphSVG(brd, svgbrd, "BRD14051GreedyOutput.svg");
    solve.SolveRandomly(brd, svgbrd);
    std::cout << "Generating Randomly SVG Output\n";
    graphSVG(brd, svgbrd, "BRD14051RandomlyOutput.svg");
    solve.SolveMyWay(brd, svgbrd);
    std::cout << "Generating MyWay SVG Output\n";
    graphSVG(brd, svgbrd, "BRD14051MyWayOutput.svg");

    std::cout << "\n";

    //Make CityList for DSJ1000
    std::cout << "CITY: DSJ1000\n";
    Citylist dsj;
    readfile("djs1000.tsp", node0, dsj);
    Citypath svgdsj;
    solve.SolveGreedy(dsj, svgdsj);
    std::cout << "Generating Greedy SVG Output\n";
    graphSVG(dsj, svgdsj, "DSJ1000GreedyOutput.svg");
    solve.SolveRandomly(dsj, svgdsj);
    std::cout << "Generating Randomly SVG Output\n";
    graphSVG(dsj, svgdsj, "DSJ1000RandomlyOutput.svg");
    solve.SolveMyWay(dsj, svgdsj);
    std::cout << "Generating MyWay SVG Output\n";
    graphSVG(dsj, svgdsj, "DSJ1000MyWayOutput.svg");

    //Make CityList for PLA85900
    std::cout << "CITY: PLA85900\n";
    Citylist pla;
    readfile("pla85900.tsp", node0, pla);
    Citypath svgpla;
    solve.SolveGreedy(pla, svgpla);
    std::cout << "Generating Greedy SVG Output\n";
    graphSVG(pla, svgpla, "PLA85900GreedyOutput.svg");
    solve.SolveRandomly(pla, svgpla);
    std::cout << "Generating Randomly SVG Output\n";
    graphSVG(pla, svgpla, "PLA85900RandomlyOutput.svg");
    solve.SolveMyWay(pla, svgpla);
    std::cout << "Generating MyWay SVG Output\n";
    graphSVG(pla, svgpla, "PLA85900MyWayOutput.svg");

    std::cout << "\n";

    //Make CityList for PR1002
    std::cout << "CITY: PR1002\n";
    Citylist pr;
    readfile("pr1002.tsp", node0, pr);
    Citypath svgpr;
    solve.SolveGreedy(pr, svgpr);
    std::cout << "Generating Greedy SVG Output\n";
    graphSVG(pr, svgpr, "PR1002GreedyOutput.svg");
    solve.SolveRandomly(pr, svgpr);
    std::cout << "Generating Randomly SVG Output\n";
    graphSVG(pr, svgpr, "PR1002RandomlyOutput.svg");
    solve.SolveMyWay(pr, svgpr);
    std::cout << "Generating MyWay SVG Output\n";
    graphSVG(pr, svgpr, "PR1002MyWayOutput.svg");

    std::cout << "\n";

    // Make CityList for USA13509
    std::cout << "CITY: USA\n";
    Citylist us;
    readfile("usa13509.tsp", node0, us);
    Citypath svgus;
    solve.SolveGreedy(us, svgus);
    std::cout << "Generating Greedy SVG Output\n";
    graphSVG(us, svgus, "us13509GreedyOutput.svg");
    solve.SolveRandomly(us, svgus);
    std::cout << "Generating Randomly SVG Output\n";
    graphSVG(us, svgus, "us13509RandomlyOutput.svg");
    solve.SolveMyWay(us, svgus);
    std::cout << "Generating MyWay SVG Output\n";
    graphSVG(us, svgus, "us13509MyWayOutput.svg");

    //CityNode node0(0, 0, 0);

    ////Make Citylist for BRD14051
    //Citylist brd;
    //readfile("brd14051.tsp", node0, brd);

    ////Make Citylist for DSJ1000
    //Citylist ds;
    //readfile("dsj1000.tsp", node0, ds);

    ////Make Citylist for PLA85900
    //Citylist pla;
    //readfile("pla85900.tsp", node0, pla);

    ////Make Citylist for PR1002
    //Citylist pr;
    //readfile("pr1002.tsp", node0, pr);

    ////Make Citylist for USA13509
    //Citylist usa;
    //readfile("usa13509.tsp", node0, usa);

    //brd.printCityNodes();
    /*ds.printCityNodes();
    pla.printCityNodes();
    pr.printCityNodes();
    usa.printCityNodes();*/

    /*Citylist test;
    readfile("testing.tsp", node0, test);

    Citypath testPath;
    TSPSolver testSolve;

    std::cout << "Solve Greedy: \n";
    testSolve.SolveGreedy(test);
    std::cout << "\n";

    std::cout << "Solve Randomly: \n";
    testSolve.SolveRandomly(test);
    std::cout << "\n";

    std::cout << "Solved my way: \n";
    testSolve.SolveMyWay(test);
    std::cout << "\n";*/

    return 0;
}