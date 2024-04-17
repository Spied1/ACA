#include <iostream>
#include <string>

class Car
{
public:
	bool cleared_by_customs;
	unsigned int engine_capacity;
	unsigned int mileage;
	unsigned int wheel_size;
	unsigned int year_of_production;
	std::string brand;
	std::string model;
	std::string Transmisssion;

	
};
int main()
{
	Car first;

	first.cleared_by_customs = true;
	first.engine_capacity = 2;
	first.mileage = 10;
	first.wheel_size = 19;
	first.year_of_production = 1885;
	first.brand = "bib bib car";
	first.model = "super cool";
	first.Transmisssion = "horse";

	return 0;
}
