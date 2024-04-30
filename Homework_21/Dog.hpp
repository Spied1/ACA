#pragma once
#include"Animal.hpp"

class Dog : public Animal
{
public:
	Dog(std::string name, bool gender, int weight, int age);

	void voice() override;
};