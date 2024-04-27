#include<iostream>
#include"Cat.hpp"

Cat::Cat(std::string name) :Animal(name)
{}

void Cat::voice()
{
	std::cout << "Cat_sound.mp4" << std::endl;
}