//#pragma comment (lib, "fltk.lib")
//#pragma comment (lib, "comctl32.lib")

#define WIN32
#define dirent direct

#ifndef FLTK_H
#define FLTK_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Input.H>

#include <iostream>
#include <string>
using std::string;
#include <sstream>

#include "CityNode.h"
#include "citylist.h"
#include "svg.h"
#include "solveTSP.h"

void open(Fl_Widget* w, void* data);
void quit(Fl_Widget* w, void* data);
void help(Fl_Widget* w, void* data);
void quitProgram(Fl_Widget* w, void* data);
void greedy(Fl_Widget* w, void* data);
void random(Fl_Widget* w, void* data);
void myWay(Fl_Widget* w, void* data);
void closeWindow(Fl_Widget* w, void* data);
void saveSVGGreedy(Fl_Widget* w, void* data);
void saveSVGRandom(Fl_Widget* w, void* data);
void saveSVGMyWay(Fl_Widget* w, void* data);


#endif
