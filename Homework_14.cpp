#include <iostream>

int** matrix(int size, int size2 = 0)
{
	if (size2 == 0)
	{
		size2 = size;
	}
	if (size <= 0)
		return nullptr;

	int** arr_matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; ++i)
	{

		arr_matrix[i] = (int*)malloc(size2 * sizeof(int*));
	}

	return arr_matrix;
}

int** init_matrix(int** matrix, int n, int m = 0)
{
	if (m == 0)
	{
		m = n;
	}
	if (matrix == nullptr)
		return nullptr;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = rand() % 10; // for better view in cmd
		}
	}

	return matrix;
}

void delete_matrix(int** arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		free(arr[i]);
		arr[i] = nullptr;
	}

	free(arr);
	arr = nullptr;
}

void print(int** matrix, int size, int size2 = 0)
{
	if (size2 == 0)
	{
		size2 == size;
	}
	if (matrix == nullptr)
		return;

	for (int i = 0; i < size; ++i)
	{

		for (int j = 0; j < size2; ++j)
		{

			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool is_prime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;

}

int* check_matrix_prime(int** matrix, int& size)
{
	int counter{};
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (is_prime(matrix[i][j]) == true)
			{
				counter++;
			}
		}
	}
	if (counter == 0)
	{
		return nullptr;
	}

	int* arr = (int*)malloc(counter * sizeof(int));

	int arr_pos = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (is_prime(matrix[i][j]) == true)
			{
				arr[arr_pos] = matrix[i][j];
				arr_pos++;
			}
		}
	}

	size = counter;
	return arr;
}

int sum(int** matrix, size_t size)
{
	int sum{};
	size = size - 1;
	int k = size - 1;

	for (int j = 0; j < size; ++j)
	{
		for (int i = size; i > j; --i)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

void change_pos(int** &matrix, size_t n, size_t m = 0)
{
	if (n == 0)
	{
		return;
	}
	if (m == 0)
	{
		m = n;
	}
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = i + 1; j < m; ++j) // Start from i + 1 to avoid swapping elements twice
		{
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main()
{
	int size{};

	int n{};
	int m{};
	std::cin >> n;
	m = n;
	int** arr = init_matrix(matrix(n, m), n, m);
	print(arr, n, m);

	std::cout << "\n" << "\n";

	change_pos(arr, m, n);
	print(arr, m, n);

	delete_matrix(arr, m);
	return 0;
}
