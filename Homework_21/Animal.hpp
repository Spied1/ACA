#pragma once
#include<string>

class Animal
{
private:
	bool m_gender;
	int m_age;
	int m_weight;
	std::string m_name;
public:
	Animal(std::string name, bool gender, int weight, int age);

	std::string get_name();

	virtual void voice() = 0;

	virtual ~Animal();
};