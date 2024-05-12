#include<iostream>
#include<vector>

class animal
{
private:
	std::string m_name;
public:

	animal(const std::string& name) :
		m_name(name) {};

	std::string get_name() const
	{
		return m_name;
	}
};

class zoo
{
private:
	std::vector<animal> m_zoo;

public:
	static zoo& object()
	{
		static zoo instance;

		return instance;
	}

	void add(const animal& temp)
	{
		m_zoo.push_back(temp);
	}
};

int main()
{
	zoo& first = zoo::object();

	animal lion("lion");

	first.add(lion);
}