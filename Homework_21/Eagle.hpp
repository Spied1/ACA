#pragma once
#include"Animal.hpp"

class Eagle : public Animal
{
public:
	Eagle(std::string name, bool gender, int weight, int age);

	void voice() override;
};