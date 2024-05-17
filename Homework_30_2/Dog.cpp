#include<iostream>
#include"Dog.hpp"

Dog::Dog(std::string name) : Animal(name) 
{}

Dog::Dog(Dog&& other)
{
	get_name() = other.get_name();
	other.get_name() = "";
}

void Dog::voice()
{
	std::cout << "Mergelyani_tak_dzayner.mp4" << std::endl;
}