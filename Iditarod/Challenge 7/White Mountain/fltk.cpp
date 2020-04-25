#include "fltk.h"

Fl_Input* fileChoice = nullptr;
std::string userFile = "";

void open(Fl_Widget* w, void* data) 
{
    Fl_File_Chooser chooser(".",                  
        "*.tsp",                        
        Fl_File_Chooser::SINGLE,     
        "Title Of Chooser");        
    chooser.show();

    while (chooser.shown())
    {
        Fl::wait();
    }

    if (chooser.value() == NULL)
    {
        fprintf(stderr, "(User hit 'Cancel')\n"); return;
    }

    fprintf(stderr, "--------------------\n");
    fprintf(stderr, "DIRECTORY: '%s'\n", chooser.directory());
    fprintf(stderr, "    VALUE: '%s'\n", chooser.value());
    fprintf(stderr, "    COUNT: %d files selected\n", chooser.count());

    std::string choice = chooser.value();
    std::istringstream is(choice);

    is >> userFile;

    Fl_Button* b = (Fl_Button*)w;
    Fl_Output* o = (Fl_Output*)b->parent()->child(6);
    o->value(userFile.c_str());

}

//Exits program
void quitProgram(Fl_Widget* w, void* data)
{
    exit(0);
}

void quit(Fl_Widget* w, void* data) 
{
    Fl_Window* window = new Fl_Window(340, 150, "Quit");
    Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Are you sure you want to quit?");
    Fl_Button* yesButton = new Fl_Button(120, 100, 100, 25, "Yes I\'m sure.");
    yesButton->callback(quitProgram);

    box->show();
    window->show();
}

//Help function
void help(Fl_Widget* w, void* data)
{
    Fl_Window* window = new Fl_Window(380, 150, "Help");
    Fl_Box* box = new Fl_Box(35, 60, 300, 35,
        "Import a TSP file you'd like to analyse.\n"
        "The TSP file must include nodes in\n"
        "the format of \"Node # -> Longitude -> Latitude\"\n"
        "Nodes must be after \"NODE_COORD_SECTION\" and\n"
        "before \"EOF\". Click which algorithm you'd like to\n"
        "use on the TSP file. Some algorithms will take some time.\n"
        "You can then save the SVG output.");
    window->show();
    box->show();
}

//Runs greedy.
void greedy(Fl_Widget* w, void* data) 
{
    std::string input = userFile;
    if (input != "") 
    {
        CityNode node(0, 0, 0);
        Citylist list;
        readfile(input, node, list);
        Citypath path;
        TSPSolver solve;

        //Run solveGreedy.
        std::string distance = std::to_string(solve.SolveGreedy(list, path));

        Fl_Button* b = (Fl_Button*)w;
        Fl_Output* o = (Fl_Output*)b->parent()->child(5);
        o->value(distance.c_str());

        //Save SVG.
        Fl_Window* window = new Fl_Window(340, 150, "SVG");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Would you like to save SVG file?");
        Fl_Button* yesButton = new Fl_Button(60, 100, 100, 25, "Yes");
        yesButton->callback(saveSVGGreedy, (void*)window);
        Fl_Button* noButton = new Fl_Button(180, 100, 100, 25, "No");
        noButton->callback(closeWindow, (void*)window);
        box->show();
        window->show();
    }

    else 
    {
        Fl_Window* window = new Fl_Window(340, 150, "Error.");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "You must first import a file.");
        box->show();
        window->show();
    }
}

//Runs random.
void random(Fl_Widget* w, void* data) 
{
    std::string input = userFile;
    if (input != "") 
    {
        CityNode node(0, 0, 0);
        Citylist list;
        readfile(input, node, list);
        Citypath path;
        TSPSolver solve;

        //Run solveRandomly and save distance value to distance
        std::string distance = std::to_string(solve.SolveRandomly(list, path));

        //Display total distance to distanceOutput (child 5)
        Fl_Button* b = (Fl_Button*)w;
        Fl_Output* o = (Fl_Output*)b->parent()->child(5);
        o->value(distance.c_str());

        //Save SVG Prompt
        Fl_Window* window = new Fl_Window(340, 150, "SVG");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Would you like to save SVG file?");
        Fl_Button* yesButton = new Fl_Button(60, 100, 100, 25, "Yes");
        yesButton->callback(saveSVGRandom, (void*)window);
        Fl_Button* noButton = new Fl_Button(180, 100, 100, 25, "No");
        noButton->callback(closeWindow, (void*)window);
        box->show();
        window->show();

    }

    else 
    {
        Fl_Window* window = new Fl_Window(340, 150, "Error.");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "You must first import a file.");
        box->show();
        window->show();
    }
}

//Runs MyWay.
void myWay(Fl_Widget* w, void* data) {
    std::string input = userFile;
    if (input != "") {

        CityNode node(0, 0, 0);
        Citylist list;
        readfile(input, node, list);
        Citypath path;
        TSPSolver solve;


        std::string distance = std::to_string(solve.SolveMyWay(list, path));


        Fl_Button* b = (Fl_Button*)w;
        Fl_Output* o = (Fl_Output*)b->parent()->child(5);
        o->value(distance.c_str());

        //Save SVG.
        Fl_Window* window = new Fl_Window(340, 150, "SVG");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Would you like to save SVG file?");
        Fl_Button* yesButton = new Fl_Button(60, 100, 100, 25, "Yes");
        yesButton->callback(saveSVGMyWay, (void*)window);
        Fl_Button* noButton = new Fl_Button(180, 100, 100, 25, "No");
        noButton->callback(closeWindow, (void*)window);
        box->show();
        window->show();
    }

    else
    {
        Fl_Window* window = new Fl_Window(340, 150, "Error.");
        Fl_Box* box = new Fl_Box(20, 40, 300, 35, "You must first import a file.");
        box->show();
        window->show();
    }
}

//Closes window.
void closeWindow(Fl_Widget* w, void* data) {
    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}

void saveSVGGreedy(Fl_Widget* w, void* data) {

    std::string input = userFile;

    CityNode node(0, 0, 0);
    Citylist list;
    readfile(input, node, list);
    Citypath path;
    TSPSolver solve;

    std::string distance = std::to_string(solve.SolveGreedy(list, path));

    std::string saveName = userFile;
    saveName.erase(saveName.end() - 4, saveName.end());
    saveName += "Greedy.svg";

    graphSVG(list, path, saveName);

    Fl_Window* o = new Fl_Window(405, 195, "Saved");
    Fl_Box* box = new Fl_Box(40, 15, 315, 95, "File saved.");
    Fl_Output* output = new Fl_Output(100, 100, 265, 60, "File Name:");
    output->value(saveName.c_str());
    o->show();
    box->show();

    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}

void saveSVGRandom(Fl_Widget* w, void* data)
{
    std::string input = userFile;

    CityNode node(0, 0, 0);
    Citylist list;
    readfile(input, node, list);
    Citypath path;
    TSPSolver solve;

    std::string distance = std::to_string(solve.SolveRandomly(list, path));

    std::string saveName = userFile;
    saveName.erase(saveName.end() - 4, saveName.end());
    saveName += "Random.svg";

    graphSVG(list, path, saveName);

    Fl_Window* o = new Fl_Window(405, 195, "Saved");
    Fl_Box* box = new Fl_Box(40, 15, 315, 95, "File saved.");
    Fl_Output* output = new Fl_Output(100, 100, 265, 60, "File Name:");
    output->value(saveName.c_str());
    o->show();
    box->show();

    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}

void saveSVGMyWay(Fl_Widget* w, void* data) 
{
  
    std::string input = userFile;

    CityNode node(0, 0, 0);
    Citylist list;
    readfile(input, node, list);
    Citypath path;
    TSPSolver solve;

    std::string distance = std::to_string(solve.SolveMyWay(list, path));

    std::string saveName = userFile;
    saveName.erase(saveName.end() - 4, saveName.end());
    saveName += "MyWay.svg";

    graphSVG(list, path, saveName);

    Fl_Window* o = new Fl_Window(405, 195, "Saved");
    Fl_Box* box = new Fl_Box(40, 15, 315, 95, "File saved.");
    Fl_Output* output = new Fl_Output(100, 100, 265, 60, "File Name:");
    output->value(saveName.c_str());
    o->show();
    box->show();

    Fl_Window* win = (Fl_Window*)data;
    win->hide();
}