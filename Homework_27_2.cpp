#include<iostream>

class Array
{
private:
	int m_size;
	int* m_arr;
public:

	Array()
	{
		m_arr = new int[1];
		m_size = 0;
	}

	Array(size_t size)
	{
		m_size = size;

		m_arr = new int[size];
	}

	Array(const Array& other)
	{
		if (this->m_size > other.m_size)
		{
			delete[] this->m_arr;
		}
		this->m_size = other.m_size;
		
		this->m_arr = new int[m_size];

		for (size_t i = 0; i < m_size; ++i)
		{
			this->m_arr[i] = other.m_size;
		}
	}

	Array& operator= (const Array& other)
	{
		if (this->m_size > other.m_size)
		{
			delete[] this->m_arr;
		}
		this->m_size = other.m_size;

		this->m_arr = new int[m_size];

		for (size_t i = 0; i < m_size; ++i)
		{
			this->m_arr[i] = other.m_size;
		}

		return *this;
	}

	int& operator[] (size_t i)
	{
		if (i >= m_size)
		{
			throw std::out_of_range("Index out of range");
		}

		return m_arr[i];
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& obj) 
	{
		for (size_t i = 0; i < obj.m_size; ++i)
		{
			os << obj.m_arr[i];
			os << " ";
		}

		return os;
	}

	~Array()
	{

	}
};

int main()
{
	Array arr(1000);

	for (int i = 0; i < 1000; ++i)
	{
		arr[i] = i;
	}

	std::cout << arr;
}