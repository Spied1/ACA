#include<iostream>
#include"Cat.hpp"

Cat::Cat(std::string name, bool gender, int weight, int age) :Animal(name,gender,weight,age)
{}

void Cat::voice()
{
	std::cout << "Cat_sound.mp4" << std::endl;
}