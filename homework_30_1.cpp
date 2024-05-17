#include <iostream>
#include <utility>


class matrix
{
private:
	int** arr;
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
		arr = new int* [n];
		for (size_t i = 0; i < n; ++i)
		{

			arr[i] = new int[m];
		}
	}

	matrix(matrix& other)
	{
		this->arr = new int* [other.n];
		for (size_t i = 0; i < other.n; ++i)
		{
			this->arr[i] = new int[other.m];
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
			this->arr = new int* [other.n];
			for (size_t i = 0; i < n; ++i)
			{
				this->arr[i] = new int[other.m];
			}
		}

		else if (this->m != other.m)
		{
			delete_matrix();
			this->arr = new int* [other.n];
			for (size_t i = 0; i < n; ++i)
			{
				this->arr[i] = new int[other.m];
			}
		}

		this->n = other.n;
		this->m = other.m;

		return *this;
	}

	matrix(matrix&& other): n(0), m(0), arr(nullptr) {
		this->n = other.n;
		this->m = other.m;
		this->arr = new int*[other.n];
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
		
		this->arr = new int* [other.n];
		for (size_t i = 0; i < n; ++i)
		{
			this->arr[i] = new int[other.m];
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
	int size{};

	int n{};
	int m{};
	std::cin >> n >> m;

	matrix first(n, m);

	first.init_matrix();
	first.print();

	std::cout << std::endl << std::endl;


	//first.transposition();
	//first.print();

	matrix other(std::move(first));

	other.print();
	
	matrix other2 = std::move(other);

	std::cout << std::endl << std::endl;
	
	other2.print();

	return 0;
}