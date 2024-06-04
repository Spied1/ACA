#include<iostream>

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

	template<typename T>
	struct node
	{
		node* m_next{};
		T m_val{};

		node(T val)
		{
			m_val = val;
		}
	};

	template<typename T>
	class list
	{
	private:
		node<T>* m_head;
	public:
		list():m_head(nullptr) {}

		void push_front(T val) 
		{
			node<T>* newNode = new node<T>(val);
			if (m_head == nullptr)
			{
				m_head = newNode;
				return;
			}

			Node<T>* current = m_head;
			while (current->next != nullptr) 
			{
				current = current->next;
			}
			current->next = newNode;
		}

		void pop_front()
		{
			node<T>* newNode = new node<T>(val);
			if (m_head == nullptr)
			{
				m_head = newNode;
				return;
			}

			node<T>* current = m_head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			delete current;
			current = nullptr;
		}

		void insert(T val, size_t i)
		{
			node<T>* newNode = new node<T>(val);
			if (m_head == nullptr)
			{
				m_head = newNode;
				return;
			}

			size_t temp = 0;
			node<T>* current = m_head;
			while (temp != i || current->next != nullptr)
			{
				current = current->m_next;
				temp++;
			}
			current->next = newNode;

			
		}



		bool hasCycle() {
			if (head == nullptr || head->next == nullptr) 
			{
				return false; 
			}

			ListNode<T>* slow = head;
			ListNode<T>* fast = head->next;

			while (fast != slow) 
			{
				if (fast == nullptr || fast->next == nullptr)
				{
					return false;
				}
				slow = slow->next;
				fast = fast->next->next;
			}

			return true;
		}

		void reverse()
		{
			node<T>* previous = nullptr;
			node<T>* current = m_head;
			node<T>* next = nullptr;

			while (current != nullptr)
			{
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}
			m_head = previous;
		}

		T& last_oc(size_t n)
		{
			node<T>* main_ptr = m_head;
			node<T>* ref_ptr = m_head;

			size_t count = 0;
			while (count < n)
			{
				ref_ptr = ref_ptr->next;
				count++;
			}

			while (ref_ptr != nullptr)
			{
				main_ptr = main_ptr->next;
				ref_ptr = ref_ptr->next;
			}

			if (main_ptr == nullptr)
			{
				return T{};
			}

			return main_ptr->data;
		}
	};
}
void print(nstd::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}

}

int main()
{
	nstd::vector<int> a = { 1,2,3,4,5,6,7,8,9,10 };
	nstd::vector<int> k(a);

	print(k);

	std::cout << std::endl;

	k.pop_front();

	print(k);
	std::cout << std::endl;

	k.push_front(111);

	print(k);
	std::cout << std::endl;

	k.insert(3, 222);
	print(k);
}


int main()
{

}