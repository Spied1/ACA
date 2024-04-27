#include<iostream>
#include"Eagle.hpp"

Eagle::Eagle(std::string name) : Animal(name) 
{}

void Eagle::voice()
{
	std::cout << "eagle_sound.mp4" << std::endl;
}
