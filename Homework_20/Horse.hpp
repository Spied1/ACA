#pragma once
#include"Animal.hpp"

class Horse : public Animal
{
public:
	Horse(std::string name);

	void voice() override;
};