#pragma once
#include"Animal.hpp"

class Cat: public Animal
{
public:
	Cat(std::string name);

	void voice() override;
};