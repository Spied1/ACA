#pragma once
#include"Animal.hpp"

class Dog : public Animal
{
public:
	Dog(std::string name);

	void voice() override;
};