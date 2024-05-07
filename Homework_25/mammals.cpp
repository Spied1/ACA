#include"mammals.hpp"
#include<iostream>

mammal::mammal(std::string type, std::string living_in) :
	animal(type, living_in)
{

}

void mammal::make_sound()
{
	std::cout << "sound of mammal" << std::endl;
}

std::string mammal::get_living()
{
	return animal::get_living();
}

mammal::~mammal()
{

}
