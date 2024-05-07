#include"fish.hpp"
#include<iostream>


fish::fish(std::string type, std::string living_in):
	animal(type,living_in)
{

}

void fish::make_sound()
{
	std::cout << "sound of fish" << std::endl;
}

std::string fish::get_living()
{
	return animal::get_living();
}

fish::~fish()
{

}
