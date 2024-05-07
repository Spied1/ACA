#pragma once
#include"animal.hpp"

class mammal : public virtual animal
{
public:
	mammal(std::string type, std::string living_in);

	void make_sound() override;

	std::string get_living() override;

	~mammal();
};
