#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Struct of animal data. 
struct Animal
{
	int id = 0;
	int age = 0;
	int amount = 0;
	int zoo = 0;
	int food = 0;
	int health = 0;

	std::shared_ptr<Animal> next = nullptr;
};

bool operator == (const Animal& hb1, const Animal& hb2);

#endif // !LINKED_LIST.H

