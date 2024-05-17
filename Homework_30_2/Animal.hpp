#pragma once
#include<string>

class Animal
{
private:
	std::string m_name;
public:
	Animal(std::string name);

	std::string get_name();

	virtual void voice();

	virtual ~Animal();
};