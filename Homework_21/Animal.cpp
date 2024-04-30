#include"Animal.hpp"
#include<iostream>

Animal::Animal(std::string name, bool gender, int weight, int age):
	m_name(name),
	m_gender(gender),
	m_weight(weight),
	m_age(age)
{}

void Animal::voice() {};

std::string Animal::get_name() 
{
	return m_name;
}
Animal::~Animal() {};