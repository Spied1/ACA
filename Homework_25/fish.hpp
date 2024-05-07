#pragma once
#include"animal.hpp"


class fish : public virtual animal
{
public:
	fish(std::string type, std::string living_in);

	void make_sound() override;

	std::string get_living() override;

	~fish();
};
