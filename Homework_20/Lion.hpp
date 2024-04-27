#pragma once
#include"Animal.hpp"

class Lion : public Animal
{
public:
	Lion(std::string name);

	void voice() override;
};