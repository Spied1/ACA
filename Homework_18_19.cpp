#include<iostream>

class Engine
{
private:
	int m_thrust;
	std::string m_manufacturer;
	std::string m_engine_name;
public:
	Engine():
		m_thrust(0),
		m_manufacturer("NO MANFUACTURER"),
		m_engine_name("NO ENGINE")
	{

	}
	Engine(int thrust, std::string manufacturer, std::string engine_name) :
		m_thrust(thrust),
		m_manufacturer(manufacturer),
		m_engine_name(engine_name)
	{}

	Engine(const Engine& other)
	{
		this->m_thrust = other.m_thrust;
		this->m_manufacturer = other.m_manufacturer;
		this->m_engine_name = other.m_engine_name;
	}


	void print()
	{
		std::cout << m_manufacturer << " " << m_engine_name << " With thrust: " << m_thrust;
	}

	~Engine()
	{

	}
};

class Arsenal
{
private:
	size_t m_weapons_capacity = 0;
	size_t m_installed_weapons = 0;
	std::string* m_weapons = nullptr;

public:
	Arsenal()
	{

	}
	Arsenal(size_t arsenal):
		m_weapons_capacity(arsenal),
		m_installed_weapons(0)
	{
		m_weapons = new std::string[arsenal];
	}

	Arsenal(const Arsenal& other)
	{
		if (this->m_weapons_capacity < other.m_weapons_capacity)
		{
			delete[] m_weapons;
			this->m_weapons = new std::string[other.m_weapons_capacity];
		}
		this->m_weapons_capacity = other.m_weapons_capacity;
		this->m_installed_weapons = other.m_installed_weapons;
		for (size_t i = 0; i < this->m_installed_weapons; ++i)
		{
			m_weapons[i] = other.m_weapons[i];
		}
	}

	const Arsenal& operator=(const Arsenal& other)
	{
		if (this->m_weapons_capacity < other.m_weapons_capacity)
		{
			delete[] m_weapons;
			m_weapons = new std::string[other.m_weapons_capacity];
		}
		this->m_weapons_capacity = other.m_weapons_capacity;
		this->m_installed_weapons = other.m_installed_weapons;

		for (size_t i = 0; i < this->m_weapons_capacity; ++i)
		{
			this->m_weapons[i] = other.m_weapons[i];
		}
		return *this;
	}
	bool add_weapon(const std::string& weapon)
	{
		bool bRes = false;
		if (m_weapons_capacity > m_installed_weapons)
		{
			m_weapons[m_installed_weapons] = weapon;
			m_installed_weapons++;
			bRes = true;
		}
		return bRes;
	}


	void print()
	{
		if (m_installed_weapons == 0)
		{
			std::cout << "No Weapons attached";
			return;
		}
		
		for (size_t i = 0; i < m_installed_weapons; ++i)
		{
			std::cout << m_weapons[i] << " ";
		}
	}

	~Arsenal()
	{
		delete[] m_weapons;
	}
};

class Plane
{
private:
	int m_speed;
	std::string m_model;
	std::string m_manufacturer;
	std::string m_type;
	Engine m_engine;
	Arsenal m_arsenal;

public:
	Plane():
		m_speed(0),
		m_model("NO MODEL"),
		m_manufacturer("NO MANUFACTURER"),
		m_type("NO TYPE"),
		m_engine(),
		m_arsenal()
	{

	}
	Plane(int speed, std::string model, std::string manufacturer, std::string type, Engine engine, Arsenal arsenal) :
		m_speed(speed),
		m_model(model),
		m_manufacturer(manufacturer),
		m_type(type),
		m_engine(engine)
	{
		m_arsenal = arsenal;
	}

	Plane(const Plane& other)
	{
		this->m_speed = other.m_speed;
		this->m_model = other.m_model;
		this->m_manufacturer = other.m_manufacturer;
		this->m_type = other.m_type;
		this->m_engine = other.m_engine;
		this->m_arsenal = other.m_arsenal;
	}

	std::string say_model()
	{
		return m_model;
	}

	void print()
	{
		std::cout << "Plane type: " << m_type << std::endl << "Plane: " << m_manufacturer << " " << m_model << std::endl << "With engine: ";
		m_engine.print();
		std::cout << std::endl << "With Maximal speed of: " << m_speed << std::endl << "With Arsenal of: ";
		m_arsenal.print();
	}

	~Plane()
	{

	}
};

class Aeroport
{
private:
	size_t m_places;
	size_t m_occupied;
	Plane** m_planes;

public:
	Aeroport(size_t places) :
		m_places(places),
		m_occupied(0)
	{
		m_planes = new Plane*[m_places];
	}

	Aeroport(const Aeroport& other)
	{
		if (other.m_places > this->m_places)
		{
			delete[] m_planes;
			this->m_planes = new Plane*[other.m_places];
		}
		this->m_places = other.m_places;
		this->m_occupied = other.m_occupied;
		for (size_t i = 0; i < m_occupied; ++i)
		{
			this->m_planes[i] = other.m_planes[i];
		}
	}

	bool landing(Plane* plane)
	{
		bool bRes = false;
		if (m_occupied < m_places)
		{
			m_planes[m_occupied] = plane;
			m_occupied++;
		}

		return bRes;
	}

	void takeoff()
	{
		if (m_occupied == 0)
		{
			std::cout << "No Planes On Site";
			return;
		}

		std::cout << "Plane: " << m_planes[m_occupied - 1]->say_model() << " just took off" << std::endl << std::endl;
		
		m_occupied--;
	}

	void takeoff(Plane* plane)
	{
		for (size_t i = 0; i < m_occupied; ++i)
		{
			if (m_planes[i]->say_model() == (plane)->say_model())
			{
				for (size_t j = i; j < m_occupied - 1; ++j)
				{
					std::swap(m_planes[i], m_planes[i + 1]);
				}
				std::cout << "Plane: " << plane->say_model() << " just took off" << std::endl << std::endl;
				std::cout << std::endl << std::endl;
				m_occupied--;
				return;
			}
		}
		std::cout << "No Such Plane On Site";
	}

	void print_occupied()
	{
		std::cout << "*******************************" << std::endl;
		std::cout << "There is: " << m_occupied << " Planes On Site" << std::endl;
		std::cout << "*******************************" << std::endl << std::endl;
	}

	void print()
	{
		if (m_occupied == 0)
		{
			std::cout << "No Planes on Site";
			return;
		}
		print_occupied();
		for (size_t i = 0; i < m_occupied; ++i)
		{
			m_planes[i]->print();
			std::cout << std::endl << std::endl << std::endl;
		}
	}
};
int main()
{
	Engine engine(10500,"Lockheed Martin", "Pratt & Whitney F119");
	Engine engine2(151, "Boeing", "CFM56-7B ENGINE");
	Arsenal arsenal(3);
	Arsenal arsenal2(0);
	arsenal.add_weapon("M61A2 Vulcan");
	arsenal.add_weapon("AIM-120 AMRAAM");
	arsenal.add_weapon("JDAM");

	Plane* raptor = new Plane(2414, "F-22 Raptor", "Lockheed Martin Corporation", "Fighter Jet", engine, arsenal);
	
	Plane* boeing = new Plane(839, "737", "Boeing", "Civilian Jet", engine2, arsenal2);

	Plane* Lightning = new Plane(3000, "F-35 Lightning II", "Lockheed Martin Corporation", "Fighter Jet", engine, arsenal);

	Plane* boeing2 = new Plane(839, "737", "Boeing", "Civilian Jet", engine2, arsenal2);

	Aeroport first(4);

	first.landing(raptor);
	first.landing(boeing);
	first.landing(Lightning);
	first.landing(boeing2);
	first.takeoff(Lightning);

	first.print();

	first.takeoff();
	first.takeoff();
	first.takeoff();
	first.print();

}