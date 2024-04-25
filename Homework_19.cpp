#include<iostream>
#include<string>

class Plain
{
private:
	int m_year_of_production;
	int m_speed;
	std::string m_manufacturer;
	std::string m_engine;
	

public:
	Plain() :
		m_year_of_production(-1),
		m_engine(""),
		m_speed(0),
		m_manufacturer("")
	{

	}
	Plain(std::string manufacturer, std::string engine, int year_of_production, int speed) :
		m_year_of_production(year_of_production),
		m_engine(engine),
		m_speed(speed),
		m_manufacturer(manufacturer)
	{

	}

	Plain(const Plain& other)
	{
		this->m_speed = other.m_speed;
		this->m_year_of_production = other.m_year_of_production;
		this->m_engine = other.m_engine;
		this->m_manufacturer = other.m_manufacturer;
	}

	const Plain& operator=(const Plain& other)
	{
		Plain temp(other);

		return temp;
	}

	~Plain() {};
};


class FighterJet : public Plain
{
private:
	std::string m_name;
public:
	FighterJet(std::string manufacturer, std::string engine, 
		int year_of_production, int speed, std::string name): 
		Plain(name,engine,year_of_production,speed),
		m_name(name)
	{

	}
	FighterJet()
	{

	}

	~FighterJet()
	{

	}
};

class CivillianJet : public Plain
{
private:
	std::string m_name;
public:
	CivillianJet(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name) :
		Plain(name, engine, year_of_production, speed),
		m_name(name)
	{

	}
	CivillianJet()
	{

	}

	~CivillianJet()
	{

	}
};

class UAV : public Plain
{
private:
	std::string m_name;
public:
	UAV(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name) :
		Plain(name, engine, year_of_production, speed),
		m_name(name)
	{

	}
	UAV()
	{

	}

	~UAV()
	{

	}
};


class seven_four_seven : public CivillianJet
{
private:
	int m_Seats_capacity;
public:
	seven_four_seven()
	{

	}
	seven_four_seven(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name,int Seats_capacity):
		CivillianJet(name, engine, year_of_production, speed,name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~seven_four_seven()
	{

	}
};

class Airobus : public CivillianJet
{
private:
	int m_Seats_capacity;
public:
	Airobus()
	{

	}
	Airobus(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		CivillianJet(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~Airobus()
	{

	}
};

class BeePlane : public CivillianJet
{
private:
	int m_Seats_capacity;
public:
	BeePlane()
	{

	}
	BeePlane(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		CivillianJet(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~BeePlane()
	{

	}
};


class F22 : public FighterJet
{
private:
	int m_Seats_capacity;
public:
	F22()
	{

	}
	F22(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		FighterJet(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~F22()
	{

	}
};

class F35 : public FighterJet
{
private:
	int m_Seats_capacity;
public:
	F35()
	{

	}
	F35(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		FighterJet(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~F35()
	{

	}
};

class SU25 : public FighterJet
{
private:
	int m_Seats_capacity;
public:
	SU25()
	{

	}
	SU25(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		FighterJet(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~SU25()
	{

	}
};

class Orlan : public UAV
{
private:
	int m_Seats_capacity;
public:
	Orlan()
	{

	}
	Orlan(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		UAV(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~Orlan()
	{

	}
};

class Predator : public UAV
{
private:
	int m_Seats_capacity;
public:
	Predator()
	{

	}
	Predator(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		UAV(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~Predator()
	{

	}
};

class Global_Hawk : public UAV
{
private:
	int m_Seats_capacity;
public:
	Global_Hawk()
	{

	}
	Global_Hawk(std::string manufacturer, std::string engine,
		int year_of_production, int speed, std::string name, int Seats_capacity) :
		UAV(name, engine, year_of_production, speed, name),
		m_Seats_capacity(Seats_capacity)
	{

	}

	~Global_Hawk()
	{

	}
};

int main()
{
	seven_four_seven Cfirst;
	Airobus Csecond;
	BeePlane cthird;
	F22 Ffirst;
	F35 Fsecond;
	SU25 Fthird;
	Orlan Ufirst;
	Orlan Usecond;
	Orlan Uthird;


}