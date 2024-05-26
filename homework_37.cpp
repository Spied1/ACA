#include <iostream>
#include <utility>
#include<string>
#include <initializer_list>

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

		vector(std::initializer_list<T> elements) :
			m_arr(new T[elements.size()])
		{
			for (const T& i : elements)
			{
				push_back(i);
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

		void pop_back()
		{
			if (m_size == 0)
			{
				return;
			}

			m_size--;
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

int main()
{
	nstd::vector<int> a = {6,5,4,3,2,1,0};
	
	for (int i = 0; i < 100; ++i)
	{
		a.push_back(i);
	}
	
	for (int i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << " ";
	}

	std::cout << std::endl << std::endl << a.size();

	a.clear();

	std::cout << std::endl << a.size();
}
