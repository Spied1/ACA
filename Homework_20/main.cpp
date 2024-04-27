#include<iostream>
#include"Horse.hpp"
#include"Lion.hpp"
#include"Cat.hpp"
#include"Dog.hpp"
#include"Animal.hpp"
#include"Eagle.hpp"

int main()
{
	//Animal** = new Animal*[5];
	Horse* first = new Horse("Horse");
	Lion* second = new Lion("Lion");
	Cat* third = new Cat("Cat");
	Dog* fourth = new Dog("Dog");
	Eagle* fifth = new Eagle("Dog");
	
	Animal** Noah_Ark = new Animal*[5];
	Noah_Ark[0] = first;
	Noah_Ark[1] = second;
	Noah_Ark[2] = third;
	Noah_Ark[3] = fourth;
	Noah_Ark[4] = fifth;

	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << "Animal " << Noah_Ark[i]->get_name() << " Makes Sound: ";
		Noah_Ark[i]->voice();
	}

}