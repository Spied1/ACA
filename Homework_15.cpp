#include <iostream>
#include <utility>

class matrix
{
private:
	int** arr;
	size_t n;
	size_t m;

public:

	matrix(size_t n_, size_t m_):
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


	first.transposition();
	first.print();

	first.delete_matrix();

	return 0;
}
