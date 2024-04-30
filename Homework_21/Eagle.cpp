#include<iostream>
#include"Eagle.hpp"

Eagle::Eagle(std::string name, bool gender, int weight, int age) :Animal(name,gender,weight,age) 
{}

void Eagle::voice()
{
	std::cout << "eagle_sound.mp4" << std::endl;
}
