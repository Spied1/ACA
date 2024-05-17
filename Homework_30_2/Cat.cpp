#include<iostream>
#include"Cat.hpp"

Cat::Cat(std::string name) :Animal(name)
{}

Cat::Cat(Cat&& other)
{
	get_name() = other.get_name();
	other.get_name() = "";
}

void Cat::voice()
{
	std::cout << "Cat_sound.mp4" << std::endl;
}