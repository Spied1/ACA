#include<iostream>
#include"Lion.hpp"


Lion::Lion(std::string name): Animal(name)
{}

void Lion::voice()
{
	std::cout << "Big_Cat_sound.mp4" << std::endl;
}