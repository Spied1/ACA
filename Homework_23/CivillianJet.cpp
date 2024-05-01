#include"CivillianJet.hpp"

CivillianJet::CivillianJet(std::string manufacturer, std::string engine,
	int year_of_production, int speed, std::string name) :
	m_name(name),
	m_engine(engine),
	m_year_of_production(year_of_production),
	m_speed(speed)
{

}
CivillianJet::CivillianJet()
{

}

void CivillianJet::give_information()
{
	std::cout << m_year_of_production << " " << m_speed << " "
		<< m_manufacturer << " " << m_engine << " " << m_name << std::endl;
}

CivillianJet::~CivillianJet()
{

}