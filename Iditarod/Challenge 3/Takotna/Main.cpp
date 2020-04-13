#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "CityNode.h"
#include "citylist.h"

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
                std::string nodeStart = "NODE COORDINATES";

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

	return 0;
}