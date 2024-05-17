#pragma once
#include"Animal.hpp"

class Dog : public Animal
{
public:
	Dog(std::string name);

	Dog(Dog&& other);

	void voice() override;
};