#include <iostream>
#include <string>
#include <list>
#include <memory>
//#include <catch2/catch.hpp>	

//Struct of animals. 
struct Animal
{
	int animal;  
	std::unique_ptr<Animal> next;
	Animal(int animal) : animal{animal}, next{ nullptr } {}

	~Animal()
	{
		std::cout << "Destroy node with animal: " << animal << '\n';
	}
};

//List struct to manage creation and deletion of nodes. 
struct List
{
	List() : head{ nullptr } {};
	void push(int animal) 
	{
		auto temp{ std::make_unique<Animal>(animal) };
		if (head)
		{
			temp->next = std::move(head);
			head = std::move(temp);
		}
		else
		{
			head = std::move(temp);
		}
	}
	void pop() 
	{
	
	}
	~List() 
	{
	
	}
	
private:
	std::unique_ptr<Animal> head;
};

int main(int argc, char** argv)
{
    //Create node n0.
	auto n0{ std::make_unique<Animal>(0) };

	//Create node n1.
	auto n1{ std::make_unique<Animal>(1) };

	//Link node n0 to n1. And so on..
	n1->next = std::move(n0);
	auto n2{ std::make_unique<Animal>(2) };
	n2->next = std::move(n1);

	//Create an object of List struct.
	List test;

	//Pushing elements to the head of the list. 
	test.push(5);
	test.push(6);
}