#ifndef LAB_2_H	
#define LAB_2_H

#include<iostream>
#include<string>

class functions
{
private:
	int a;
	int x, y;

public:
	//Default constructor.
	functions(int x1_, int y1_) { x = x1_; y = y1_; }

	//Copy constructor.
	functions(const functions& item) { x = item.x; y = item.y; }

	int getX() { return x; }
	int getY() { return y; }
};
#endif