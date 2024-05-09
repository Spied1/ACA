#include<iostream>

class Animal
{
private:
	static int count;
public:

	Animal()
	{
		count++;
	}
	int get_count()
	{
		return Animal::count;
	}
};

class Lion : public Animal
{

};

int Animal::count = 0;

int main()
{
	
	Animal a;
	Animal b;
	Animal c;
	Animal d;
	Lion e;

	std::cout << a.get_count();
}