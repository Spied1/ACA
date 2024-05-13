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

class zoo {
private:
    static bool m_created;
    std::vector<animal> m_zoo;
    static zoo instance;

    zoo() = default;

public:
    static zoo& object() 
    {
        if (!m_created) 
        {
            instance = zoo();
            m_created = true;
        }
        return instance;
    }

    void add(const animal& temp) 
    {
        m_zoo.push_back(temp);
    }
};

bool zoo::m_created = false;
zoo zoo::instance;

int main()
{
	zoo& first = zoo::object();

	animal lion("lion");

	first.add(lion);
}
