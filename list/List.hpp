#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <exception>
#include <string>

#include "../Reverse_Iterator.hpp"


namespace ft
{
	template<typename T, class Allocator = std::allocator<T> >
	class List
	{
		class Node
		{
			public:
			T		_data;
			Node	*_next;
			Node	*_prev;
		};

		// rebinding allocator to get a <node> type one
		typedef typename Allocator::template rebind<Node>::other _node_alloc_type;

		public:

		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;
		typedef T			value_type;
		typedef Allocator	allocator_type;

		struct Iterator // bi_directionnal iterator
		{

			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef T*			pointer;
			typedef T&			reference;
			typedef T			value_type;
			typedef const T&	const_reference;
			typedef const T*	const_pointer;

			Iterator()
			{
				_node = NULL;
			};

			Iterator(Node *node)
			{
				_node = node;
			};

			Iterator(const Iterator& it)
			{
				_node = it._node;
			};

			void operator = (const Iterator& it)
			{
				_node = it._node;
			};

			~Iterator() {};

			bool operator == (const Iterator& it) const
			{
				return (it._node == _node);
			};

			bool operator != (const Iterator& it) const
			{
				return (it._node != _node);
			};

			T& operator * ()
			{
				return (_node->_data);
			};

			T* operator -> ()
			{
				return (&_node->_data);
			};

			Iterator& operator ++ ()
			{
				_node = _node->_next;
				return (*this);
			};

			Iterator& operator -- ()
			{
				_node = _node->_prev;
				return (*this);
			};

			Iterator operator ++ (int)
			{
				Iterator b = *this;

				_node = _node->_next;
				return (b);
			};

			Iterator operator -- (int)
			{
				Iterator b = *this;

				_node = _node->_prev;
				return (b);
			};

		private:
			Node			*_node;
		};

		struct Const_Iterator: public Iterator
		{
			Const_Iterator(): Iterator(){};
			//Const_Iterator(const Const_Iterator& i): Iterator()
			Const_Iterator(Node *node): Iterator(node){};
		};

		typedef Iterator iterator;
		typedef Reverse_Iterator<Iterator> reverse_iterator;
		typedef Const_Iterator const_iterator;
		/*
		**CONSTRUCTORS
		*/

		List(): _head(NULL), _tail(NULL), _size(0)
		{
			_past_end._prev = _head;
			_past_begin._next = _tail;
		};

		List(const List& list): _head(NULL), _tail(NULL), _size(0)
		{
			// Deep copy;
			for (int i = 0; i < list._size; i++)
			{
				push_back(list[i]);
			}
		};

		void operator = (const List& list)
		{
			// deep copy;
			clear();
			for (int i = 0; i < list._size; i++)
			{
				push_back(list[i]);
			}
		};

		~List()
		{
			// normal deallocations
			/*for (int i = 0; i < _size; i++)
			{
				Node *b = _head->_next;
				_allocator.deallocate(_head, 1);
				_head = b;
			}*/
			clear();
		};

		List(size_type size, T value = T())
		{
			_head = NULL;
			_tail = NULL;
			_size = 0;

			if (size <= 0)
				return ;
			for (int i = 0; i < size; i++)
				push_back(value);
		};

		template<typename input_iterator>
		List(input_iterator first, input_iterator last)
		{
			_head = NULL;
			_tail = NULL;
			_size = 0;
			while (first != last)
				push_back(*(first++));
		}

		/*
		** pushing MODIFIERS
		*/

		void push_back(const T& value)
		{
			if (_size == 0)
			{
				_head = allocate_node(NULL, NULL, value);
				_tail = _head;
				_size += 1;
				set_up_head_tail();
				return ;
			}
			Node *b;
			b = allocate_node(NULL, _tail, value);
			_tail->_next = b;
			_tail = b;
			_size += 1;
			set_up_head_tail();

		};

		void push_front(const T& value)
		{
			if (_size == 0)
			{
				_head = allocate_node(NULL, NULL, value);
				_tail = _head;
				_size += 1;
				set_up_head_tail();
				return ;
			}
			Node *b;
			b = allocate_node(_head, NULL, value);
			_head->_prev = b;
			_head = b;
			_size += 1;
			set_up_head_tail();
		};

		void pop_front()
		{
			if (empty())
				return ;
			Node *b = _head->_next;
			if (b)
				b->_prev = NULL;
			_allocator.deallocate(_head, 1);
			_head = b;
			_size -= 1;
			set_up_head_tail();
		};

		void pop_back()
		{
			if (empty())
				return ;
			Node *b = _tail->_prev;
			if (b)
				b->_next = NULL;
			_allocator.deallocate(_tail, 1);
			_tail = b;
			_size -= 1;
			set_up_head_tail();
		};


		void assign(size_type n, const T& value) // missing the input iterator part and maybe with a T array
		{
			clear();
			List<T> b_list(n, value);
			*this = b_list;
		};

		template<typename input_iterator>
		void assign(input_iterator first, input_iterator last) // missing the input iterator part and maybe with a T array
		{
			clear();
			List<T> b_list(first, last);
			*this = b_list;
		};

		iterator insert(iterator pos, const value_type& value)
		{
			//Node *node = allocate_node((*pos)._next);
			iterator base = begin();
			Node *node = _head;

			while (base != pos)
			{
				base++;
				node = node->_next;
			}

			Node *new_node = allocate_node(NULL, NULL, value);
			new_node->_next = node;
			new_node->_prev = node->_prev;

			if (node == _head)
				_head = new_node;
			if (node == &_past_end)
				_tail = new_node;
			if (node == &_past_begin)
				_head = new_node;
			node->_prev->_next = new_node;
			node->_prev = new_node;
			_size += 1;
			set_up_head_tail();
			return (iterator(new_node));
		}

		void insert(iterator pos, size_type n, const value_type& value)
		{
			while (n)
			{
				insert(pos, value);
				n--;
			}
		}

		template<typename input_iterator>
		iterator insert(iterator pos, input_iterator first, input_iterator last)
		{
			iterator ret = pos;

			while (first != last)
			{
				ret = insert(pos, *first);
				first++;
			}
			return (ret);
		}

		iterator erase(iterator pos)
		{
			iterator base = begin();
			Node *node = _head;

			while (base != pos)
			{
				base++;
				node = node->_next;
			}
			base = iterator(node->_next);
			delete_node(node);
			return (base);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it = first;
			while (first != last)
			{
				it = first;
				it = erase(it);
				first++;
			}
			return (it);
		}

		void swap(List& x) // untested
		{
			Node *b;

			b = _head;
			_head = x._head;
			x._head = b;
			b = _tail;
			_tail = x._tail;
			x._tail = b;

			int size_b;
			size_b = _size;
			_size = x._size;
			x._size = size_b;
			set_up_head_tail();
			x.set_up_head_tail();
		}

		/*
		** Iterations
		*/
		Iterator begin()
		{
			Iterator it(_head);
			return (it);
		}

		Iterator end()
		{
			Iterator it(&_past_end);

			return (it);
		}

		const_iterator begin() const
		{
			const_iterator it(_head);
			return (it);
		}

		const_iterator end() const
		{
			const_iterator it(&_past_end);

			return (it);
		}

		Iterator rbegin()
		{
			Iterator it(_tail);

			return (it);
		}

		Iterator rend()
		{
			Iterator it(&_past_begin);

			return (it);
		}
		/*
		** ACCESS
		** Don't forget the const equivalent
		*/

		T& front()
		{
			if (empty())
				throw(std::out_of_range("List empty, operation not permitted"));
			return (_head->_data);
		};

		T& back()
		{
			if (empty())
				throw(std::out_of_range("List empty, operation not permitted"));
			return (_tail->_data);
		};

		const T& front() const
		{
			if (empty())
				throw(std::out_of_range("List empty, operation not permitted"));
			return (_head->_data);
		};

		const T& back() const
		{
			if (empty())
				throw(std::out_of_range("List empty, operation not permitted"));
			return (_tail->_data);
		};

		T& operator [] (size_type idx)
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (int i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		const T& operator [] (size_type idx) const
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (int i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		T& at(size_type idx)
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (int i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		const T& at(size_type idx) const
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (int i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		/*
		** CAPACITY
		*/

		size_type size() const
		{
			return (_size);
		}

		bool empty() const
		{
			return (_size == 0);
		}

		size_type max_size() const
		{
			return (std::numeric_limits<difference_type>::max());
		}

		void clear()
		{
			for (int i = 0; i < _size; i++)
			{
				Node *b = _head->_next;
				_allocator.deallocate(_head, 1);
				_head = b;
			}
			_head = NULL;
			_tail = NULL;
			_size = 0;
		}

		void resize(size_type n, T value = T())
		{
			if (n > _size)
			{
				while (_size < n)
					push_back(value);
			}
			else if (n < _size)
			{
				while (_size > n)
					pop_back();
			}
		};

		/*
		** OPERATIONS
		*/

		void remove(const T& value)
		{
			Node *b = _head;
			Node *next;
			size_type size = _size;
			for (int i = 0; i < size; i++)
			{
				next = b->_next;
				if (b->_data == value)
				{
					delete_node(b);
					b = next;
				}
				else
					b = b->_next;
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred) // untested
		{
			Node *b = _head;
			Node *next;
			size_type size = _size;
			for (int i = 0; i < size; i++)
			{
				next = b->_next;
				if (Predicate(b->_data) == true)
				{
					delete_node(b);
					b = next;
				}
				else
					b = b->_next;
			}
		}

		void unique()
		{
			Node *b = _head;
			Node *next;
			size_type size = _size;
			for (int i = 0; i < size; i++)
			{
				next = b->_next;
				if (b->_prev && b->_prev->_data == b->_data)
				{
					delete_node(b);
					b = next;
				}
				else
					b = b->_next;
			}
		}

		// Left to do unique(2) with pred

		void sort() // bubble sort
		{
			T b;
			for (int i = _size - 1; i >= 1; i--)
			{
				for (int j = 0; j <= i - 1; j++)
				{
					if ((*this)[j + 1]  < (*this)[j])
					{
						b = (*this)[j + 1];
						(*this)[j + 1] = (*this)[j];
						(*this)[j] = b;
					}
				}
			}
		};

		template<class Compare>
		void sort(Compare comp) // bubble sort -> not tested
		{
			T b;
			for (int i = _size - 1; i >= 1; i--)
			{
				for (int j = 0; j <= i - 1; j++)
				{
					if (comp((*this)[j + 1], (*this)[j]))
					{
						b = (*this)[j + 1];
						(*this)[j + 1] = (*this)[j];
						(*this)[j] = b;
					}
				}
			}
		};

		void merge(List& x)
		{
			if (this == &x)
				return ;
	//		sort();
	//		x.sort();
			push_list(x);
			x._size = 0;

		}

		template<class Compare>
		void merge(List& x, Compare comp)
		{
			if (this == &x)
				return ;
	//		sort(comp);
	//		x.sort(comp);
			push_list(x);
			x._size = 0;
		//	sort(comp);
		}

		void reverse()
		{
			T b;

			for (int i = 0, j = _size - 1; i < j; i++, j--)
			{
				b = (*this)[i];
				(*this)[i] = (*this)[j];
				(*this)[j] = b;
			}
		}

		void splice(iterator pos, List& x)
		{

			if (x.empty())
				return ;
			Node *node = get_node(pos);

	//		if (node == _head)
	//			_head = x._head;
			if (node == &_past_end)
			{
				_tail->_next = x._head;
				x._head->_prev = _tail;
				_tail = x._tail;
				_size += x.size();
			}
			else if (node == &_past_begin)
			{
				_head->_prev = x._tail;
				x._tail->_next = _head;
				_head = x._head;
				_size += x.size();
			}
			else
			{
				node->_prev->_next = x._head;
				x._head->_prev = node->_prev;
				x._tail->_next = node;
				node->_prev = x._tail;
				_size += x.size();
			}
			set_up_head_tail();

			x._size = 0;
		}

		void splice(iterator pos, List& x, iterator i)
		{
			if (x.empty())
				return ;
			Node *node = get_node(pos);
			Node *new_node = x.get_node(i);
			x.pop_node(new_node);

			if (node == &_past_end)
			{
				new_node->_prev = _tail;
				_tail->_next = new_node;
				_tail = new_node;
				_size += 1;
			}
			else if (node == &_past_begin)
			{
				new_node->_next = _head;
				_head->_prev = new_node;
				_head = new_node;
				_size += 1;
			}
			else
			{
				node->_prev->_next = new_node;
				new_node->_prev = node->_prev;
				new_node->_next = node;
				node->_prev = new_node;
				_size += 1;
			}
			if (node == _head)
				_head = new_node;
			set_up_head_tail();
		}

		void splice(iterator pos, List& x, iterator first, iterator last)
		{
			iterator b;
			while (first != last)
			{
				b = first;
				first++;
				splice(pos, x, b);
			}
		}

		private:
		Node				*_head;
		Node				*_tail;
		Node				_past_end;
		Node				_past_begin;
		size_type			_size;
		_node_alloc_type 	_allocator;

		void set_up_head_tail()
		{
			_head->_prev = &_past_begin;
			_tail->_next = &_past_end;
			_past_begin._next = _head;
			_past_end._prev = _tail;
		}

		Node *allocate_node(Node *next, Node *prev)
		{
			Node *b = _allocator.allocate(1);
			b->_next = next;
			b->_prev = prev;
			return (b);
		}

		Node *allocate_node(Node *next, Node *prev, const T& value)
		{
			Node *b = allocate_node(next, prev);
			b->_data = value;
			return (b);
		}

		void push_list(List& list)
		{
			if (list.empty())
				return ;
			if (!empty())
			{
				_tail->_next = list._head;
				list._head->_prev = _tail;
				_tail = list._tail;
			}
			else
			{
				_head = list._head;
				_tail = list._tail;
			}
			_size += list.size();
			set_up_head_tail();
		}

		void push_node(Node *node, Node *next, Node *prev)
		{
			if (prev)
				prev->_next = node;
			else
				_head = node;
			node->_prev = prev;
			if (next)
				next->_prev = node;
			else
				_tail = prev;
			node->_next = next;
			_size += 1;
			set_up_head_tail();
		}

		void delete_node(Node *node)
		{
			pop_node(node);
			deallocate_node(node);
		}

		void pop_node(Node* node)
		{
			if (node == &_past_end || node == &_past_begin)
				return ;
			if (node->_next)
				node->_next->_prev = node->_prev;
			if (node->_prev)
				node->_prev->_next = node->_next;
			if (node == _head)
				_head = node->_next;
			if (node == _tail)
				_tail = node->_prev;
			_size -= 1;
			set_up_head_tail();
			//deallocate_node(node);
		}

		void deallocate_node(Node *node)
		{
			// call the destructor with destroy ?
			_allocator.deallocate(node, 1);
		}

		iterator insert_in_place(iterator pos, Node *new_node)
		{
			std::cout << "lol\n";
			Node* node = get_node(pos);

			//Node *new_node = allocate_node(NULL, NULL, value);
			new_node->_next = node;
			new_node->_prev = node->_prev;
			std::cout << "lol\n";
			if (node == _head)
				_head = new_node;
			if (node == &_past_end)
				_tail = new_node;
			if (node == &_past_begin)
				_head = new_node;
			node->_prev->_next = new_node;
			node->_prev = new_node;
			_size += 1;
			std::cout << "lol1\n";
			set_up_head_tail();
			std::cout << "lol2\n";
			return (iterator(new_node));
		}

		/*template<typename input_iterator>
		void insert_in_place(iterator pos, input_iterator first, input_iterator last)
		{
			while (first != last)
			{
				insert_in_place(pos, get_node(first));
				first++;
			}
		}*/

		Node* get_node(iterator it)
		{
			iterator base = begin();

			Node *node = _head;

			if (it == --begin())
				return (&_past_begin);
			while (base != it)
			{
				base++;
				node = node->_next;
			}
			return (node);
		}
	friend void swap(List<T, Allocator>& x, List<T, Allocator>& y);

	};
	template<typename T, class Allocator>
	void swap(List<T, Allocator>& x, List<T, Allocator>& y) // friend
	{
		x.swap(y);
	};
}

template <class T, class Allocator>
bool operator == (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	if (x.size() == y.size())
	{
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] != y[i])
				return (false);
		}
		return (true);
	}
	return (false);
};

template <class T, class Allocator>
bool operator != (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	return (!(x == y));
};

template <class T, class Allocator>
bool operator < (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	// check comportement on empty containers
	for (int i = 0, j = 0; i < x.size() && j < y.size(); i++, j++)
	{
		if (!(x[i] < y[i]))
			return (false);
	}
	return (true);
};

template <class T, class Allocator>
bool operator <= (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	// check comportement on empty containers
	for (int i = 0, j = 0; i < x.size() && j < y.size(); i++, j++)
	{
		if (!(x[i] <= y[i]))
			return (false);
	}
	return (true);
};

template <class T, class Allocator>
bool operator > (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	// check comportement on empty containers
	return (!(x < y));
};
template <class T, class Allocator>
bool operator >= (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
{
	// check comportement on empty containers
	return (!(x <= y));
};

#endif
