#pragma once
#include"fish.hpp"
#include"mammals.hpp"
#include"animal.hpp"

class amphibian : public mammal, public fish
{
public:
    amphibian(std::string type, std::string living_in1, std::string living_in2);

    void make_sound() override;

    std::string get_living();
};