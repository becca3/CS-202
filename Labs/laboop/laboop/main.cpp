#include <iostream>
#include <iomanip>

#include "Widget.h" 
#include "Application.h"

class MyApplication : public Application
{
public:
	MyApplication();
	~MyApplication();

	void init();

	void run()
	{
		draw();
	}
};

int main(int argc, char** argv)
{
	MyApplication app;

	app.init();
	app.kill();
	app.draw();

	return 0;
}