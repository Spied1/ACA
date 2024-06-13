#include<iostream>
#include<map>

std::map<int, std::string> lib;

std::string digit_to_string(int n)
{
	if (lib.find(n) == lib.end())
	{
		return lib[111];
	}

	return lib[n];
}



int main()
{
	lib[0] = "zero";
	lib[1] = "one";
	lib[2] = "two";
	lib[3] = "three";
	lib[4] = "four";
	lib[5] = "five";
	lib[6] = "six";
	lib[7] = "seven";
	lib[8] = "eight";
	lib[9] = "nine";
	lib[111] = "undefined";

	for (int i = -10; i <= 10; ++i)
	{
		std::cout << digit_to_string(i) << std::endl;
	}
	
	return 0;
}
