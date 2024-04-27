#include"Animal.hpp"
#include<iostream>

Animal::Animal(std::string name):m_name(name) 
{}

void Animal::voice() {};

std::string Animal::get_name() 
{
	return m_name;
}
Animal::~Animal() {};