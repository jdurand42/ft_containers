#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <exception>
#include <string>

#include <cstddef>
#include <limits>
#include "../utils/Utils.hpp"

#include "../utils/Reverse_Iterator.hpp"


namespace ft
{
	template<typename T, class Allocator = Allocator<T> >
	class List
	{
		class Node
		{
			public:
			Node()
			{
				_next = NULL;
				_prev = NULL;
			}
			Node(const Node& node)
			{
				_data = node._data;
				_next = node._next;
				_prev = node._prev;
			}
			void operator = (const Node& node)
			{
				_data = node._data;
				_next = node._next;
				_prev = node._prev;
			}
			Node(Node *prev, Node *next, const T& value = T())
			{
				_data = value;
				_next = next;
				_prev = prev;
			}

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

		protected:
			Node			*_node;
		};

		class Const_Iterator: public Iterator
		{
			public:
			Const_Iterator(): Iterator()
			{
			}

			Const_Iterator(const Const_Iterator& i): Iterator(i)
			{}

			Const_Iterator(const Iterator& i): Iterator(i)
			{}

			void operator = (const Const_Iterator& i)
			{
				Iterator::_node = i._node;
			}

			virtual ~Const_Iterator() {};

			Const_Iterator(T* t): Iterator(t)
			{}

			const T& operator * ()
			{
				//std::cout << "bonjour";
				return (Iterator::_node->_data);
			};


			const T* operator -> () const
			{
				return (Iterator::_node);
			};


		};

		class Const_Reverse_Iterator: public Reverse_Iterator<Iterator>
		{
			public:
			Const_Reverse_Iterator() {};
			Const_Reverse_Iterator(const Iterator& i): Reverse_Iterator<Iterator>(i)
			{};
			Const_Reverse_Iterator(const Const_Reverse_Iterator& i): Reverse_Iterator<Iterator>(i)
			{};
			Const_Reverse_Iterator(const Reverse_Iterator<Iterator>& i): Reverse_Iterator<Iterator>(i)
			{};
			void operator = (const Reverse_Iterator<Iterator>& i)
			{
				Reverse_Iterator<Iterator>::_base = i._base;
			}

			const_reference operator * () const
			{
				const_iterator a = Reverse_Iterator<Iterator>::_base;
				return (*a);
			//	return (*_base);
			};

			const_pointer operator -> () const
			{
				const_iterator a = Reverse_Iterator<Iterator>::_base;
				return (Reverse_Iterator<Iterator>::_base::_node);
			};
		};

		typedef Iterator iterator;
		typedef Reverse_Iterator<Iterator> reverse_iterator;
		typedef Const_Iterator const_iterator;
		typedef Const_Reverse_Iterator const_reverse_iterator;
		/*
		**CONSTRUCTORS
		*/

		List(): _head(NULL), _tail(NULL), _size(0)
		{
			_past_end._prev = _head;
			_past_begin._next = _tail;
			set_up_head_tail();
		};

		List(const List& list): _head(NULL), _tail(NULL), _size(0)
		{
			// Deep copy;
			for (size_type  i = 0; i < list._size; i++)
			{
				push_back(list[i]);
			}
			set_up_head_tail();
		};

		void operator = (const List& list)
		{
			// deep copy;
			clear();
			for (size_type  i = 0; i < list._size; i++)
			{
				push_back(list[i]);
			}
			set_up_head_tail();
		};

		~List()
		{
			// normal deallocations
			/*for (size_type  i = 0; i < _size; i++)
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

			set_up_head_tail();
			if (size <= 0)
				return ;
			for (size_type  i = 0; i < size; i++)
				push_back(value);
			set_up_head_tail();
		};

		template<typename input_iterator>
		List(input_iterator first, input_iterator last)
		{
			_head = NULL;
			_tail = NULL;
			_size = 0;
			if (first == last)
				return ;
			while (first != last)
				push_back(*(first++));
			set_up_head_tail();
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
			_allocator.destroy(_head);
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
			_allocator.destroy(_tail);
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
			iterator ret = begin();
			size_type i = 0;

			while (ret != pos)
			{
				ret++;
				i++;
			}

			while (first != last)
			{
				insert(pos, *first);
				first++;
			}

			Node *b = _head;
			for (size_type ib = 0; ib < i; ib++)
				b = b->_next;
			return (iterator(b));
		}

		iterator erase(iterator pos)
		{
			iterator base = begin();
			Node *node = _head;
			size_type i = 0;

			while (base != pos)
			{
				base++;
				i++;
				node = node->_next;
			}

			delete_node(node);
			if (i == _size)
				return (end());
			node = _head;
			while (i > 0)
			{
				node = node->_next;
				i--;
			}
			return (iterator(node));
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
				first = erase(first);

			return (first);
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
			const_iterator it(_tail);
			if (_tail)
				it++;
			return (it);
		}

		reverse_iterator rbegin()
		{
			reverse_iterator it(_tail);

			return (it);
		}

		reverse_iterator rend()
		{
			reverse_iterator it(&_past_begin);

			return (it);
		}

		const_reverse_iterator rbegin() const
		{
			const_reverse_iterator it(_tail);

			return (it);
		}

		const_reverse_iterator rend() const
		{
			const_reverse_iterator it(&_past_begin);

			return (it);
		}


		/*
		** ACCESS
		** Don't forget the const equivalent
		*/

		T& front()
		{
			return (_head->_data);
		};

		T& back()
		{
			return (_tail->_data);
		};

		const T& front() const
		{
			return (_head->_data);
		};

		const T& back() const
		{
			return (_tail->_data);
		};

		T& at(size_type idx)
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (size_type  i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		const T& at(size_type idx) const
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (size_type  i = 0; i != idx; i++)
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
			return (std::numeric_limits<size_type>::max() / sizeof(Node));
		}

		void clear()
		{
			for (size_type  i = 0; i < _size; i++)
			{
				Node *b = _head->_next;
				_allocator.destroy(_head);
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

			while (b != &_past_end)
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

			while (b != &_past_end)
			{
				next = b->_next;
				if (pred(b->_data) == true)
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
			Node *node = _head->_next;
			Node *next = node->_next;

			if (size() <= 1)
				return ;
			while (next != &_past_end)
			{
				next = node->_next;
				if (node->_data == node->_prev->_data)
				{
					delete_node(node);
					node = next;
				}
				else
					node = node->_next;
			}
		}

		template<class Predicate>
		void unique(Predicate pred)
		{
			Node *node = _head->_next;
			Node *next = node->_next;

			if (size() <= 1)
				return ;
			while (next != &_past_end)
			{
				next = node->_next;
				if (pred(node->_data, node->_prev->_data))
				{
					delete_node(node);
					node = next;
				}
				else
					node = node->_next;
			}
		}

		// Left to do unique(2) with pred

		void sort() // bubble sort
		{
			T b;
			for (size_type  i = _size - 1; i >= 1; i--)
			{
				for (size_type  j = 0; j <= i - 1; j++)
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
			for (size_type  i = _size - 1; i >= 1; i--)
			{
					for (size_type j = 0; j <= i - 1; j++)
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
			if (_size == 0)
			{
				//assign(x.begin(), x.end());
				//splice(begin(), x);
				_head = x._head;
				_tail = x._tail;
				_size += x.size();
				set_up_head_tail();
				x._size = 0;
				//x.clear();
				return ;
			}

			iterator first = begin();
			iterator last = end();
			iterator first2 = x.begin();
			iterator last2 = x.end();
			iterator b;

			while (first2 != last2 && first != last)
			{
				if (*first2 >= *first)
					first++;
				else
				{
					splice(first, x, first2);
					first2 = x.begin();
				}
			}
			if (first2 != last2)
			{
				splice(end(), x);
			}
			x._size = 0;

		}

		template<class Compare>
		void merge(List& x, Compare comp)
		{
			if (this == &x)
				return ;
			if (_size == 0)
			{
					//assign(x.begin(), x.end());
					//splice(begin(), x);
				_head = x._head;
				_tail = x._tail;
				_size += x.size();
				set_up_head_tail();
				x._size = 0;
					//x.clear();
				return ;
			}

			iterator first = begin();
			iterator last = end();
			iterator first2 = x.begin();
			iterator last2 = x.end();

			while (first2 != last2 && first != last)
			{
				if (!comp(*first2, *first))
					first++;
				else
				{
						//b = first2;
					splice(first, x, first2);
					first2 = x.begin();
				}
			}
			if (first2 != last2)
			{
				splice(end(), x);
			}
			x._size = 0;
		}

		void reverse()
		{
			T b;

			for (size_type i = 0, j = _size - 1; i < j; i++, j--)
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
			if (_head)
				_head->_prev = &_past_begin;
			if (_tail)
				_tail->_next = &_past_end;
			_past_begin._next = _head;
			_past_end._prev = _tail;
		}

		Node *allocate_node()
		{
			Node *b = _allocator.allocate(1);
		//	_allocator.construct(b);
		//	b->_next = next;
		//	b->_prev = prev;
			return (b);
		}

		Node *allocate_node(Node *next, Node *prev, const T& value = T())
		{
			Node *b = allocate_node();
			Node base(prev, next, value);
			_allocator.construct(b, base);
			//b->_data = value;
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
			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
		}

		iterator insert_in_place(iterator pos, Node *new_node)
		{
			Node* node = get_node(pos);

			//Node *new_node = allocate_node(NULL, NULL, value);
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

		//private to search
		T& operator [] (size_type idx)
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (size_type i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		const T& operator [] (size_type idx) const
		{
			if (idx < 0 || idx >= _size)
				throw (std::out_of_range("Index is out of range"));
			Node *b;
			b = _head;
			for (size_type  i = 0; i != idx; i++)
				b = b->_next;
			return (b->_data);
		};

		};
	template<typename T, class Allocator>
	void swap(List<T, Allocator>& x, List<T, Allocator>& y) // friend
	{
		x.swap(y);
	};

	template <class T, class Allocator>
	bool operator == (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
	{
		if (x.size() == y.size())
		{
			typename ft::List<T,Allocator>::const_iterator it = x.begin();
			typename ft::List<T,Allocator>::const_iterator it2 = y.begin();
			typename ft::List<T,Allocator>::const_iterator end = x.end();
			for (; it != end; it++, it2++)
			{
				if (*it != *it2)
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
		typename ft::List<T,Allocator>::const_iterator it = x.begin();
		typename ft::List<T,Allocator>::const_iterator it2 = y.begin();
		typename ft::List<T,Allocator>::const_iterator end = x.end();
		typename ft::List<T,Allocator>::const_iterator end2 = y.end();

		while (it != end)
		{
			if (it2 == end2 || *it2 < *it)
				return (false);
			else if (*it < *it2)
				return (true);
			it++;
			it2++;
		}
		return (it2 != end2);
	};

	template <class T, class Allocator>
	bool operator <= (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
	{
		return (!(y < x));
	};

	template <class T, class Allocator>
	bool operator > (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
	{
		// check comportement on empty containers
		return (y < x);
	};

	template <class T, class Allocator>
	bool operator >= (const ft::List<T,Allocator>& x, const ft::List<T,Allocator>& y)
	{
		// check comportement on empty containers
		return (!(x < y));
	};
}



/*
template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}*/

#endif
