#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>

class Widget
{
public:
	Widget()
	{

	}

	~Widget()
	{

	}

	virtual void init()
	{
		std::cout << __FUNCTION__ << " initialised.\n";
	}

	virtual void kill()
	{
		std::cout << __FUNCTION__ << " destroyed.\n";
	}

	virtual void draw()
	{
		std::cout << __FUNCTION__ << " drawn.\n";
	}
};

#endif	