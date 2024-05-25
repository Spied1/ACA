#include <iostream>
#include <utility>
#include<string>

template<typename T>
class matrix
{
private:
	T** arr;
	size_t n;
	size_t m;

private:
	void delete_matrix()
	{
		for (int i = 0; i < n; ++i)
		{
			delete[] arr[i];
			arr[i] = nullptr;
		}

		delete[] arr;
		arr = nullptr;
	}

public:

	matrix(size_t n_, size_t m_) :
		arr(nullptr),
		n(n_),
		m(m_)
	{
		if (n <= 0)
			arr = nullptr;

		if (m == 0)
		{
			m = n;
		}
		arr = new T* [n];
		for (size_t i = 0; i < n; ++i)
		{

			arr[i] = new T[m];
		}
	}

	matrix(matrix& other)
	{
		this->arr = new T* [other.n];
		for (size_t i = 0; i < other.n; ++i)
		{
			this->arr[i] = new T[other.m];
		}

		for (size_t i = 0; i < other.n; ++i)
		{
			for (size_t j = 0; j < other.m; ++j)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}

		this->n = other.n;
		this->m = other.m;
	}

	matrix& operator=(const matrix& other)
	{
		if (this->n != other.n)
		{
			delete_matrix();
			this->arr = new T* [other.n];
			for (size_t i = 0; i < n; ++i)
			{
				this->arr[i] = new T[other.m];
			}
		}

		else if (this->m != other.m)
		{
			delete_matrix();
			this->arr = new T* [other.n];
			for (size_t i = 0; i < n; ++i)
			{
				this->arr[i] = new T[other.m];
			}
		}

		this->n = other.n;
		this->m = other.m;

		return *this;
	}

	matrix(matrix&& other) : n(0), m(0), arr(nullptr) {
		this->n = other.n;
		this->m = other.m;
		this->arr = new T* [other.n];
		for (size_t i = 0; i < other.m; ++i)
		{
			arr[i] = other.arr[i];
		}

		other.n = 0;
		other.m = 0;
		other.arr = nullptr;
	}

	matrix& operator=(matrix&& other)
	{

		this->arr = new T* [other.n];
		for (size_t i = 0; i < n; ++i)
		{
			this->arr[i] = new T[other.m];
		}
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}
		this->n = other.n;
		this->m = other.m;

		other.~matrix();

		return *this;

	}

	//prefix
	matrix& operator++()
	{
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				++(this->arr[i][j]);
			}
		}

		return *this;
	}

	//postfix
	matrix& operator++(int)
	{
		matrix temp = *this;
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				++(temp.arr[i][j]);
			}
		}

		return temp;
	}

	int*& operator[](int i)
	{
		return arr[i];
	}

	void init_matrix(size_t max_number = 10)
	{
		if (m == 0)
		{
			m = n;
		}

		if (arr == nullptr)
			arr = nullptr;

		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				arr[i][j] = rand() % max_number;
			}
		}
	}

	void print()
	{
		if (m == 0)
		{
			m = n;
		}
		if (arr == nullptr)
			return;

		for (size_t i = 0; i < n; ++i)
		{

			for (size_t j = 0; j < m; ++j)
			{

				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	std::string get_string() const
	{
		if (arr == nullptr)
			return " ";

		std::string res = " ";
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{

				res += (std::to_string(arr[i][j]) + " ");
			}
			res += "\n";
		}

		return res;
	}

	int get_m()
	{
		return m;
	}

	int get_n()
	{
		return n;
	}

	void transposition()
	{
		if (n == m || m == 0)
		{
			for (size_t i = 0; i < n; ++i)
			{
				for (size_t j = i + 1; j < m; ++j)
				{
					std::swap(arr[i][j], arr[j][i]);
				}
			}
			return;
		}

		T** arr_matrix = new T* [m];
		for (size_t i = 0; i < m; ++i)
		{
			arr_matrix[i] = new T[n];
		}

		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				arr_matrix[j][i] = arr[i][j];
			}
		}

		delete_matrix();

		arr = arr_matrix;
		std::swap(n, m);
	}

	~matrix()
	{
		delete_matrix();

	}
};

int main()
{
	matrix<float> first(10,16);

	first.init_matrix();
	first.print();
}