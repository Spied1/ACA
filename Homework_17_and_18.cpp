#include <iostream>
#include <utility>

class matrix
{
private:
	int** arr;
	size_t n;
	size_t m;

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
		arr = new int* [n];
		for (size_t i = 0; i < n; ++i)
		{

			arr[i] = new int[m];
		}
	}

	matrix(const matrix& other)
	{
		this->arr = other.arr;
		this->n = other.n;
		this->m = other.m;
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

	void clear()
	{
		for (int i = 0; i < n; ++i)
		{
			delete[] arr[i];
			arr[i] = nullptr;
		}

		delete[] arr; // problem
		arr = nullptr;
		n = 0;
		m = 0;
	}

	const matrix& operator=(const matrix& other)
	{
		this->arr = other.arr;
		this->n = other.n;
		this->m = other.m;

		return *this;
	}

	const matrix operator+(const matrix& other)
	{
		
		if (n != other.n || m != other.m)
		{
			matrix Temp(n, m);
			return Temp;
		}
		

		
		matrix Temp(n, m);
		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				Temp.arr[i][j] = arr[i][j] + other.arr[i][j];
			}
		}

		return Temp;
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

		int** arr_matrix = new int* [m];

		for (size_t i = 0; i < m; ++i)
		{
			arr_matrix[i] = new int[n];
		}

		for (size_t i = 0; i < n; ++i)
		{
			for (size_t j = 0; j < m; ++j)
			{
				arr_matrix[j][i] = arr[i][j];
			}
		}

		clear();

		arr = arr_matrix;
		std::swap(n, m);
	}

	~matrix()
	{
		if (n != 0)
		{
			clear();
		}
	}
};



int main()
{
	int size{};

	int n{};
	int m{};
	std::cin >> n >> m;

	matrix first(n, m);
	matrix second(n, m);
	first.init_matrix();
	

	std::cout << std::endl << std::endl;

	second.init_matrix();
	

	//first.clear();

	matrix third = first + second;
	first.print();
	std::cout << std::endl << std::endl;
	second.print();
	std::cout << std::endl << std::endl;
	
	third.print();
	//first.transposition();
	//first.print();
	return 0;
}
