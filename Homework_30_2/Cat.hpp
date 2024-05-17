#pragma once
#include"Animal.hpp"

class Cat: public Animal
{
public:
	Cat(std::string name);

	Cat(Cat&& other);

	void voice() override;
};