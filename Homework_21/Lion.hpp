#pragma once
#include"Animal.hpp"

class Lion : public Animal
{
public:
	Lion(std::string name, bool gender, int weight, int age);

	void voice() override;
};