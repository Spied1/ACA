#pragma once
#include"Animal.hpp"

class Cat: public Animal
{
public:
	Cat(std::string name, bool gender, int weight, int age);

	void voice() override;
};