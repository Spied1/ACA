#include"Plain.h"
#include<string>
#include<iostream>

class UAV : public Plain
{
private:
	int m_year_of_production = 0;
	int m_speed = 0;
	std::string m_manufacturer = "";
	std::string m_engine = "";
	std::string m_name = "";
public:

	UAV(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name);

	UAV();

	void give_information() override;

	virtual ~UAV();
};