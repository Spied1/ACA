#include<iostream>
#include"Horse.hpp"


Horse::Horse(std::string name): Animal(name) {}

void Horse::voice()
{
	std::cout << "horse_sound.mp4" << std::endl;
} 