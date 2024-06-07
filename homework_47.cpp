#include<iostream>
#include<vector>

namespace nstd
{
	template<typename T>
	class vector
	{
	private:
		size_t m_capacity;
		size_t m_size;
		T* m_arr;
	public:
		vector(size_t size = 0) :
			m_size(size),
			m_capacity(m_size * 2 + 1),
			m_arr(new T[m_capacity])
		{

		}

		vector(const nstd::vector<T>& other)
		{
			m_capacity = other.m_capacity;
			m_size = other.m_size;

			m_arr = new T[m_capacity];

			for (size_t i = 0; i < m_size; ++i)
			{
				m_arr[i] = other.m_arr[i];
			}
		}

		vector(std::initializer_list<T> elements) :
			m_arr(new T[elements.size()])
		{
			for (const T& i : elements)
			{
				push_back(i);
			}
		}

		vector& operator=(nstd::vector<T>& other)
		{
			this->m_capacity = other.m_capacity;
			this->m_size = other.m_size;

			this->m_arr = new T[m_capacity];

			for (size_t i = 0; i < this->m_size; ++i)
			{
				this->m_arr[i] = other.m_arr[i];
			}
		}

		void reserve(size_t new_size)
		{
			if (new_size < m_capacity)
			{
				return;
			}


			T* temp = new T[new_size]{};

			for (size_t i = 0; i < m_size; ++i)
			{
				temp[i] = m_arr[i];
			}

			delete[] m_arr;
			m_arr = temp;
			m_capacity = new_size;
		}

		void push_back(const T& element)
		{
			if (m_size == m_capacity)
			{
				reserve(m_size * 2 + 1);
			}

			m_arr[m_size] = element;
			m_size++;
		}

		void push_front(const T& element)
		{
			push_back(element);
			for (size_t i = m_size - 1; i > 0; --i)
			{
				std::swap(m_arr[i], m_arr[i - 1]);
			}
		}

		void pop_back()
		{
			if (m_size == 0)
			{
				return;
			}

			m_size--;
		}

		void pop_front()
		{
			for (size_t i = 0; i < m_size - 1; ++i)
			{
				std::swap(m_arr[i], m_arr[i + 1]);
			}

			pop_back();
		}

		void insert(size_t pos, const T& element)
		{
			push_back(element);

			for (size_t i = m_size - 1; i > pos + 1; --i)
			{
				std::swap(m_arr[i], m_arr[i - 1]);
			}
		}

		bool empty()
		{
			return !m_size;
		}

		const size_t& size()
		{
			return m_size;
		}

		T& operator[](const size_t& index)
		{
			return m_arr[index];
		}

		void clear()
		{
			m_size = 0;
		}

		~vector()
		{
			delete[] m_arr;
		}
	};
}

void merge(std::vector<int> a, std::vector<int> b, std::vector<int>& c)
{
	c.clear();
	while (!a.empty() && !b.empty())
	{
		if (a.front() > b.front())
		{
			c.push_back(b.front());
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a.front());
			a.erase(a.begin());
		}
	}

	while (!a.empty())
	{
		c.push_back(a.front());
		a.erase(a.begin());
	}

	while (!b.empty())
	{
		c.push_back(b.front());
		b.erase(b.begin());
	}
}

void merge_sort(std::vector<int>& vec)
{
	if (vec.size() <= 1)
	{
		return;
	}

	int mid = vec.size() / 2;

	std::vector<int> first(vec.begin(), vec.begin() + mid);

	std::vector<int> second(vec.begin() + mid, vec.end());

	merge_sort(first);
	merge_sort(second);

	merge(first, second, vec);
}

int partition(std::vector<int>& vec, int l, int h)
{
	int pivot = vec[l]; 

	int left_wall = l;

	for (int i = l + 1; i < h; ++i) {
		if (vec[i] < pivot) {
			left_wall++;
			std::swap(vec[i], vec[left_wall]);
		}
	}
	std::swap(vec[l], vec[left_wall]);

	return left_wall;
}

void quick_sort(std::vector<int>& vec, int l, int h)
{
	if (l < h)
	{
		int pivot_l = partition(vec, l, h);
		quick_sort(vec, l, pivot_l - 1);

		quick_sort(vec, pivot_l + 1, h);
	}
}

int main()
{
	std::vector<int> vec;

	for (int i = 10; i > -1; --i)
	{
		vec.push_back(i);
	}

	quick_sort(vec,0,vec.size());

	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << "  ";
	}

	return 0;
}