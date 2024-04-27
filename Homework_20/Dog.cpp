#include<iostream>
#include"Dog.hpp"

Dog::Dog(std::string name) : Animal(name) 
{}

void Dog::voice()
{
	std::cout << "Mergelyani_tak_dzayner.mp4" << std::endl;
}