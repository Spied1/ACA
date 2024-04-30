#include<iostream>
#include"Horse.hpp"


Horse::Horse(std::string name, bool gender, int weight, int age): Animal(name,gender,weight,age) {}

void Horse::voice()
{
	std::cout << "horse_sound.mp4" << std::endl;
} 