#ifndef LINKED_LIST.H
#define LINKED_LIST.H

//Struct of animal data. 
struct Animal
{
	int id = 0;
	int age = 0;
	int amount = 0;
	int zoo = 0;
	int food = 0;
	int health = 0;

	int value;
	Animal* prev;
	Animal* succ;
	Animal(const int& v, Animal* p = nullptr, Animal* s = nullptr)
		: value{ v }, prev{ p }, succ{ s } { }
};

#endif // !LINKED_LIST.H

