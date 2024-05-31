#include<iostream>

void print()
{

}

template <typename T, typename... K>
void print(T var1, K... var2)
{
    std::cout << var1 << std::endl;

    print(var2...);
}

int main()
{
    print(1, 3.14, true, "153");

    return 0;
}