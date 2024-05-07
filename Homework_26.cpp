#include<iostream>


class A
{
public:
	int operator() (int a, int b) const
	{
		return a + b;
	}

};


int functor(const A& functor)
{
	return functor(100,23);
}


int main()
{
	std::cout << functor;
}