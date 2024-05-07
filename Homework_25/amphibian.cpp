#include "amphibian.hpp"
#include <iostream>

amphibian::amphibian(std::string type, std::string living_in1, std::string living_in2):
    mammal(type, living_in1),
    fish(type, living_in2) {}

void amphibian::make_sound()
{
    std::cout << "amphibian sound" << std::endl;
}

std::string amphibian::get_living()
{
    std::string result = "";
    result += mammal::get_living();
    result += fish::get_living();

    return result;
}