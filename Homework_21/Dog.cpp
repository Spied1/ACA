#include<iostream>
#include"Dog.hpp"

Dog::Dog(std::string name, bool gender, int weight, int age) :Animal(name,gender,weight,age) 
{}

void Dog::voice()
{
	std::cout << "Merelyani_tak_dzayner.mp4" << std::endl;
}