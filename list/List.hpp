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
		class Iterator
		{
			public:
			Iterator()
			{
				_t = NULL;
			};

			Iterator(const Iterator& it)
			{
				_t = it->_t;
			};

			~Iterator()
			{};

			void operator = (const Iterator& it)
			{
				_t = it->_t;
			};

			bool operator == (const Iterator& it)
			{
				return (it->_t == _t);
			};

			bool operator != (const Iterator& it)
			{
				return (it->_t != _t);
			};

			T& operator * ()
			{
				return (this->_t->_t);
			};

			T* operator ->()
			{
				return (&this->_t->_t);
			};



			private:
			El<T>* _t;
		};


		public:
		List()
		{
			_el = NULL;
			_end = _allocator.allocate(1);
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
			clear();
			// avec iterator
		};

		~List() // WHAT THE FUCK !!!!
		{
			clear();
		};

		void operator = (const List& list)
		{

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
			El<T>* b = _el;
			int i;
			for (i = 0; i < _size - 1; i++)
				b = b->next;
			return (b->_t);

			/*int i = 0;
			while (b->next != NULL)
			{
				b = b->next;
				i++;
			}*/

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
				_el->next = _end;
				_size = 1;
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
				_el->next = _end;
				return ;
			}
			El<T>* it = _el;
			for (int i = 0; i < _size - 1; i++)
				it = it->next;
			it->next = b;
			b->prev = it;
			b->next = _end;
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
				it->prev->next = _end;
			_allocator.deallocate(it, 1);
			_size -= 1;
		};

		/*Iterator begin()
		{
			return (Iterator());
		};*/

		void clear()
		{
			if (empty())
				return ;
			El<T>* b = _el;
			while (_size--)
			{
				pop_front();
			}
		};

		void swap(List& list)
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
		El<T>			*_end;
		unsigned int	_size;
		unsigned int	_max_size;
		Allocator		_allocator;

		El<T>			*get_first();
		El<T>			*get_last();

	};
};
