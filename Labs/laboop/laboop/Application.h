#ifndef APPLICATION_H
#define APPLICATION_H

#include "Widget.h"

class Application :
	public Widget
{
public: 
	Application();
	~Application();

	bool init();
	void kill();
	void run();

};


#endif // ! APPLICATION_H
