#include<iostream>
#include<algorithm>
#include<vector>

class animal
{
private:
	float m_weight;
	std::string m_name;
	
public:
	explicit animal():
		m_name(0),
		m_weight(0)
	{

	}

	explicit animal(std::string name, float weight) :
		m_name(name),
		m_weight(weight)
	{

	}

	explicit animal(const animal& other)
	{
		m_weight = other.m_weight;
		m_name = other.m_name;
	}

	explicit animal(animal&& other)
	{
		m_weight = other.m_weight;
		m_name = other.m_name;

		other.m_name = "";
		other.m_weight = 0;
	}

	animal& operator=(const animal& other)
	{
		this->m_weight = other.m_weight;
		this->m_name = other.m_name;

		return *this;
	}

	animal& operator=(animal&& other)
	{
		this->m_name = other.m_name;
		this->m_weight = other.m_weight;

		other.m_name = "";
		other.m_weight = 0;

		return *this;
	}

	std::string give_name()
	{
		return m_name;
	}

	float give_weight()
	{
		return m_weight;
	}

	bool operator==(const animal& other)
	{
		return this->m_weight == other.m_weight;
	}

	bool operator>(const animal& other)
	{
		
		return this->m_weight > other.m_weight;
	}

	bool operator<(const animal& other)
	{
		return this->m_weight < other.m_weight;
	}

	~animal()
	{

	}
};


int main()
{
	animal first("Lion", 190);
	animal second("Rat", 1);
	animal third("Eagle", 4);
	animal fourth("Cat", 5);
	animal fiffth("Ape", 180);

	std::vector<animal> zoo;

	zoo.push_back(first);
	zoo.push_back(second);
	zoo.push_back(third);
	zoo.push_back(fourth);
	zoo.push_back(fiffth);

	std::sort(zoo.rbegin(), zoo.rend());
	
	
	for (int i = 0; i < zoo.size(); ++i)
	{
		std::cout << zoo[i].give_name() << " " << zoo[i].give_weight() << std::endl;
	}


}