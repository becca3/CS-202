#define WIN32
#define dirent direct

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "citylist.h"
#include "citynode.h"
#include "cpath.h"
#include "solveTSP.h"
#include "svg.h"
#include "fltk.h"

int main(int argc, char** argv) {
	// Main Window
	Fl_Double_Window* window = new Fl_Double_Window(810, 370, "TSPLIB Solve.");

	{ Fl_Menu_Bar* menuBar
		= new Fl_Menu_Bar(0, 0, 85, 25);

	menuBar->add("File/Open", FL_CTRL + 'open', open);

	menuBar->add("File/Quit", FL_CTRL + 'quit', quit);

	menuBar->add("Help/Help", FL_CTRL + 'help', help);
	}

	//Greedy.
	{ Fl_Button* greedyButton
		= new Fl_Button(55, 280, 180, 45, "Greedy");
	greedyButton->callback(greedy);
	}

	//Random.
	{ Fl_Button* randomButton
		= new Fl_Button(325, 280, 180, 45, "Random");
	randomButton->callback(random);
	}

	//SolveMyWay.
	{ Fl_Button* myWayButton
		= new Fl_Button(585, 280, 180, 45, "MyWay");
	myWayButton->callback(myWay);
	}

	//Import.
	{ Fl_Button* importButton
		= new Fl_Button(280, 35, 280, 70, "Import TSPLIB");
	importButton->callback(open);
	}

	//Total Distance Output.
	{ Fl_Output* distanceOutput
		= new Fl_Output(330, 190, 175, 55, "Total Distance Traveled:");
	}

	//File Selected Output.
	{ Fl_Output* fileOutput
		= new Fl_Output(220, 135, 425, 35, "File Selected:");
	}


	//Main FLTK window
	window->end();
	window->resizable();
	window->show(argc, argv);

	return (Fl::run());
}

