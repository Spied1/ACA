#include<iostream>
#include"Lion.hpp"


Lion::Lion(std::string name, bool gender, int weight, int age): Animal(name,gender,weight,age)
{}

void Lion::voice()
{
	std::cout << "Big_Cat_sound.mp4" << std::endl;
}