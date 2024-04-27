#pragma once
#include"Animal.hpp"

class Eagle : public Animal
{
public:
	Eagle(std::string name);

	void voice() override;
};