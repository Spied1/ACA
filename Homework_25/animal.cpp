#include"animal.hpp"
#include<iostream>

animal::animal() = default;

animal::animal(std::string type, std::string living_in):
	m_type(type), 
	m_living_in(living_in)
{}

void animal::make_sound()
{
	std::cout << "sound of undefined animal" << std::endl;
}

std::string animal::get_living()
{
	return m_living_in;
}

animal::~animal(){}