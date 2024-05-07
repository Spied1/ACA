#include<iostream>
#include<string>
#include"fish.hpp"
#include"mammals.hpp";
#include"amphibian.hpp"

int main()
{
	//fish a("fish", "water");
	//mammal b("lion", "somewhere");
	amphibian c("frog", "water", "swamp");

	//std::cout << a.get_living() << std::endl << b.get_living() << std::endl;
	std::cout << c.get_living();
}