#include"Plain.h"
#include<string>
#include<iostream>
class FighterJet : public Plain
{
private:
	int m_year_of_production = 0;
	int m_speed = 0;
	std::string m_manufacturer = "";
	std::string m_engine = "";
	std::string m_name = "";
public:

	FighterJet(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name);

	FighterJet();

	void give_information() override;

	virtual ~FighterJet();
};