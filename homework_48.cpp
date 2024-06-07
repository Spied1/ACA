#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> vec;

	for (int i = 10; i > -1; --i)
	{
		vec.push_back(i);
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << "  ";
	}

	return 0;
}