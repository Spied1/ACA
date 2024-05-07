#pragma once
#include<string>

class animal
{
private:
	std::string m_type;
	std::string m_living_in;

public:
	animal();

	animal(std::string type, std::string living_in);

	virtual void make_sound();

	virtual std::string get_living();

	virtual ~animal();
};
