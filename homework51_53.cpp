#include<iostream>

namespace nstd
{
	template<typename T>
	struct node
	{
		node* m_next{};
		T m_val{};

		node(T val) : m_val(val), m_next(nullptr) {}
	};

	template<typename T>
	class list
	{
	private:
		node<T>* m_head;
	public:
		list() : m_head(nullptr) {}

		~list() {
			while (m_head) {
				node<T>* temp = m_head;
				m_head = m_head->m_next;
				delete temp;
			}
		}

		void push_front(T val)
		{
			node<T>* newNode = new node<T>(val);
			if (m_head == nullptr)
			{
				m_head = newNode;
			}
			else
			{
				node<T>* current = m_head;
				while (current->m_next != nullptr)
				{
					current = current->m_next;
				}
				current->m_next = newNode;
			}
		}

		void pop_front()
		{
			if (m_head == nullptr)
			{
				return;
			}

			node<T>* temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}

		void insert(T val, size_t i)
		{
			node<T>* newNode = new node<T>(val);
			if (m_head == nullptr)
			{
				m_head = newNode;
				return;
			}

			if (i == 0) {
				newNode->m_next = m_head;
				m_head = newNode;
				return;
			}

			size_t temp = 0;
			node<T>* current = m_head;
			while (temp < i - 1 && current->m_next != nullptr)
			{
				current = current->m_next;
				temp++;
			}
			newNode->m_next = current->m_next;
			current->m_next = newNode;
		}

		void reverse()
		{
			node<T>* previous = nullptr;
			node<T>* current = m_head;
			node<T>* next = nullptr;

			while (current != nullptr)
			{
				next = current->m_next;
				current->m_next = previous;
				previous = current;
				current = next;
			}
			m_head = previous;
		}



		class iterator
		{
		private:
			node<T>* m_current;
		public:

			iterator(node<T>* start) : m_current(start) {}

			T& operator*()
			{
				return m_current->m_val;
			}

			iterator& operator++()
			{
				m_current = m_current->m_next;
				return *this;
			}

			bool operator!=(const iterator& other)
			{
				return m_current != other.m_current;
			}

			bool operator==(const iterator& other)
			{
				return m_current == other.m_current;
			}
		};

		iterator erase(iterator pos)
		{
			if (pos == end())
			{
				return end();
			}

			if (pos == begin())
			{
				node<T>* temp = m_head;
				m_head = m_head->m_next;
				delete temp;
				return iterator(m_head);
			}

			node<T>* current = m_head;
			while (current->m_next != pos.m_current)
			{
				current = current->m_next;
			}

			current->m_next = pos.m_current->m_next;
			delete pos.m_current;

			return iterator(current->m_next);
		}

		iterator begin()
		{
			return iterator(m_head);
		}

		iterator end()
		{
			return iterator(nullptr);
		}
	};

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

		

		class iterator
		{
		private:
			T* m_ptr;
		public:
			iterator(T* ptr) : m_ptr(ptr) {}

			T& operator*()
			{
				return *m_ptr;
			}

			iterator& operator++()
			{
				++m_ptr;
				return *this;
			}

			iterator operator++(int)
			{
				iterator temp = *this;
				++(*this);
				return temp;
			}

			iterator& operator--()
			{
				--m_ptr;
				return *this;
			}

			iterator operator--(int)
			{
				iterator temp = *this;
				--(*this);
				return temp;
			}

			iterator operator+(size_t n) const
			{
				return iterator(m_ptr + n);
			}

			iterator operator-(size_t n) const
			{
				return iterator(m_ptr - n);
			}

			bool operator!=(const iterator& other) const
			{
				return m_ptr != other.m_ptr;
			}

			bool operator==(const iterator& other) const
			{
				return m_ptr == other.m_ptr;
			}

			iterator erase(iterator pos)
			{
				if (pos == end())
				{
					return end();
				}

				iterator it = pos;
				for (; it != end() - 1; ++it)
				{
					*it = *(it + 1);
				}

				--m_size;
				return pos;
			}
		};

		iterator begin()
		{
			return iterator(m_arr);
		}

		iterator end()
		{
			return iterator(m_arr + m_size);
		}
	};

	template<typename T>
	class stackV
	{
	private:
		size_t m_size;
		vector<T> m_cont;
	public:
		stackV():
			m_size(0)
		{
			
		}

		stackV(const stackV& other)
		{
			m_size = other.m_size;
			m_cont = other.m_cont;
		}

		stackV& operator=(const stackV& other)
		{
			this->m_size = other.m_size;
			this->m_cont = other.m_cont;
		}

		void push(T elem)
		{
			m_cont.push_back();
			m_size++;
		}

		void pop()
		{
			m_size--;
		}

		size_t size()
		{
			return m_size;
		}

		T& top()
		{
			return m_cont[m_size - 1];
		}
	};

	template<typename T>
	class stackL
	{
	private:
		list<T> m_list;

	public:
		void push(const T& val)
		{
			m_list.push_front(val);
		}

		void pop()
		{
			m_list.pop_front();
		}

		T& top()
		{
			return *m_list.begin();
		}

		bool empty() const
		{
			return m_list.begin() == m_list.end();
		}

		size_t size()
		{
			size_t size = 0;
			for (auto it = m_list.begin(); it != m_list.end(); ++it)
			{
				++size;
			}
			return size;
		}
	};
}



int main()
{
	
	
	return 0;
}
