#pragma once
#include"Animal.hpp"

class Horse : public Animal
{
public:
	Horse(std::string name, bool gender, int weight, int age);

	void voice() override;
};