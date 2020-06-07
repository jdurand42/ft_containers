#include <string>
#include <iostream>

namespace ft
{
	template<typename T>
	struct El
	{
		/* forme coplienne ?*/
		//public:
		El()
		{
			next = NULL;
			prev = NULL;
		};
		El(T& t): _t(t)
		{
			next = NULL;
			prev = NULL;
		};
		El(const El& el): _t(el.t)
		{
			next = NULL;
			prev = NULL;
		};
		~El() {};

		El *next;
		El *prev;
		T _t;
	};

	template<typename T, class Allocator = std::allocator<El<T> > >
	class List
	{
		public:
		struct Iterator
		{
			Iterator()
			{
				_el = NULL;
			};

			Iterator(const Iterator& it)
			{
				_el = it._el;
			};

			~Iterator()
			{};

			Iterator& operator = (const Iterator& it)
			{
				_el = it._el;
				return (*this);
			};

			bool operator == (const Iterator& it)
			{
				return (it._el == _el);
			};

			bool operator != (const Iterator& it)
			{
				return (it._el != _el);
			};

			T& operator * ()
			{
				return (this->_el->_t);
			};

			T* operator ->()
			{
				return (&this->_el->_t);
			};

			Iterator& operator ++()
			{
				this->_el = this->_el->next;
				return (*this);
			};

			Iterator& operator --()
			{
				this->_el = this->_el->prev;
				return (*this);
			};

			Iterator operator ++ (int)
			{
				Iterator b = *this;

				this->_el = this->_el->next;
				return (b);
			};

			Iterator operator -- (int)
			{
				Iterator b = *this;

				this->_el = this->_el->prev;
				return (b);
			};

			El<T>* _el;
		};



		public:
		List()
		{
			_el = NULL;
			_end->prev = NULL;
			_size = 0;
			_max_size = 0;
		};

		List(unsigned int size, T t)
		{
			_el = NULL;
			while (size--)
			{
				push_front(t);
			}
		};

		List(const List& list)
		{
			// avec iterator
			Iterator end = list.end();
			Iterator begin = list.begin();

			_size = 0;
			_max_size = 0;
			while (--end != begin)
			{
				push_front(*end);
			}
		};

		~List() // WHAT THE FUCK !!!!
		{
			clear();
		};

		void operator = (const List& list) // not implemented yet, needs const iterator
		{
			clear();

			/*_size = 0;
			_max_size = 0;
			El<T> *b = list._el;
			while (b)
			{
				push_front(b->_t);
				b = b->next;
			}*/
		};

		/* Methods */
		bool empty() const
		{
			if (_size == 0)
				return true;
			return false;
		};

		unsigned int size() const
		{
			return (_size);
		};

		unsigned int max_size() const
		{
			return (_max_size);
		}

		T& front()
		{
			return (_el->_t);
		};

		T& back()
		{
			El<T>* b = access_last();
			return (b->_t);
		};

		void push_front(T t)
		{
			El<T>* b;

			b = _allocator.allocate(1);
			_allocator.construct(b, t);
			if (_el == NULL)
			{
				_el = b;
				_el->next = &_end;
				_size = 1;
				_end.prev = _el;
				return ;
			}
			b->next = _el;
			_el->prev = b;
			_el = b;
			_size += 1;
		};

		void push_back(T t)
		{
			El<T>* b;

			b = _allocator.allocate(1);
			_allocator.construct(b, t);
			if (_el == NULL)
			{
				_el = b;
				_size = 1;
				_el->next = &_end;
				_end.prev = _el;
				return ;
			}
			El<T>* it = _el;
			for (int i = 0; i < _size - 1; i++)
				it = it->next;
			it->next = b;
			b->prev = it;
			b->next = &_end;
			_end.prev = b;
			_size += 1;
		};

		void pop_front()
		{
			if (empty())
				return ;
			El<T>* b = _el->next;
			if (b)
				b->prev = NULL;
			_allocator.deallocate(_el, 1);
			_el = b;
			_size -= 1;
		};

		void pop_back()
		{
			if (empty())
				return ;
			El<T>* it = _el;
			for (int i = 0; i < _size - 1; i++)
				it = it->next;
			if (it->prev)
				it->prev->next = &_end;
			_allocator.deallocate(it, 1);
			_size -= 1;
		};

		Iterator begin()
		{
			Iterator it;
			it._el = _el;
			return (it);
		};

		Iterator end()
		{
			Iterator it;
			it._el = &_end;
			return (it);
		};

		void clear()
		{
			if (empty())
				return ;
			/*
			El<T>* b = _el;
			while (_size--)
			{
				pop_front();
			}*/
			Iterator it(begin());
			Iterator end2(end());
			while (it != end2)
			{
				_allocator.deallocate(it->_el, 1);
				it++;
			}
			_size = 0;
			_max_size = 0;
			_end.prev = 0;
		};

		void swap(List& list) // not implemented yet
		{
			El<T>* b;
			b = list->_el;
			list->_el = _el;
			_el = b;
			// Change size and everything
		};

		void remove();
		void remove_if();

		private:
		El<T>			*_el;
		El<T>			_end;
		unsigned int	_size;
		unsigned int	_max_size;
		Allocator		_allocator;

		El<T>*			access_first()
		{
			return (_el);
		};

		El<T>*			access_last()
		{
			El<T> *b = _el;
			for (int i = 0; i < _size - 1; i++)
				b = b->next;
			return (b);
		};


	};
};
