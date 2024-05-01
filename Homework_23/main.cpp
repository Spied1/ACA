#include<iostream>
#include<string>
#include"Plain.h"
#include"CivillianJet.hpp"
#include"FighterJet.hpp"
#include"UAV.hpp"

int main()
{
	CivillianJet* Csecond = new CivillianJet("Boing", "SomeEngine",
		1999, 200, "AeroBus");

	FighterJet* Fsecond = new FighterJet("LockHead", "SomeEngine",
		2010, 2000, "F-32");

	UAV* Ufirst = new UAV("LockHead", "SomeEngine",
		1999, 200, "Predator");

	Csecond->give_information();
	Fsecond->give_information();
	Ufirst->give_information();
}