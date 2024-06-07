
namespace nstd
{
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
		list() :m_head(nullptr) {}

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
