#include <iostream>
#include <string>

namespace ft
{
	#define CAPACITY 5

	template<typename T, class Allocator = std::allocator<T> >
	class Vector
	{

		typedef size_t		size_type;
		typedef ptrdiff_t		difference_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef T			type;

		public:
		struct Iterator // random access iterator
		{
			Iterator()
			{
				_t = NULL;
			};

			Iterator(const Iterator& it)
			{
				_t = it._t;
			};

			void operator = (const Iterator& it)
			{
				_t = it._t;
			};

			~Iterator() {};

			bool operator == (const Iterator& it)
			{
				return (it._t == _t);
			};

			bool operator != (const Iterator& it)
			{
				return (it._t != _t);
			};

			T& operator * ()
			{
				return (*_t);
			};

			T* operator -> ()
			{
				return (_t);
			};

			Iterator& operator ++ ()
			{
				_t = _t + 1;
				return (*this);
			};

			Iterator& operator -- ()
			{
				_t = _t - 1;
				return (*this);
			};

			Iterator operator ++ (int)
			{
				Iterator b = *this;

				_t = _t + 1;
				return (b);
			};

			Iterator operator -- (int)
			{
				Iterator b = *this;

				_t = _t - 1;
				return (b);
			};

			Iterator operator + (difference_type n)
			{
				Iterator b;

				b._t = _t + n;
				return (b);
			};

			Iterator operator - (difference_type n)
			{
				Iterator b;

				b._t = _t - n;
				return (b);
			};

			difference_type operator - (Iterator& it)
			{
				return (_t - it._t);
			};

			void operator += (difference_type n)
			{
				_t += n;
			};

			void operator -= (difference_type n)
			{
				_t += n;
			};

			Iterator operator [] (difference_type n)
			{
				Iterator b;

				b._t = _t + n;
				return (b);
			};

			bool operator < (const Iterator& it)
			{
				return (_t < it._t);
			};

			bool operator <= (const Iterator& it)
			{
				return (_t <= it._t);
			};

			bool operator > (const Iterator& it)
			{
				return (_t > it._t);
			};

			bool operator >= (const Iterator& it)
			{
				return (_t >= it._t);
			};

			T			*_t;
		};

		Vector()
		{
			//v = new T[CAPACITY];
			_v = _allocator.allocate(CAPACITY);
			_size = 0;
			_capacity_size = CAPACITY;
		};

		~Vector()
		{
			_allocator.deallocate(_v, _capacity_size);
		};

		Vector(size_type size, T value)
		{
			//v = new T[size + CAPACITY];
			_v = _allocator.allocate(CAPACITY + size);
			_size = size;
			_capacity_size = size + CAPACITY;

			for (size_t i = 0; i < _size; i++)
				_v[i] = value;
		};

		/*
		** SHOULD I USE CONSTRUCT AND DESTORY?
		*/

		Vector(const Vector& v)
		{
			_v = _allocator.allocate(v._capacity_size);
			_size = v._size;
			_capacity_size = v._capacity_size;

			for (size_t i = 0; i < _size; i++)
				_v[i] = v._v[i];
		};

		void operator = (const Vector& v)
		{
			_allocator.deallocate(_v, _capacity_size);

			_v = _allocator.allocate(v._capacity_size);
			_size = v._size;
			_capacity_size = v._capacity_size;

			for (size_t i = 0; i < _size; i++)
				_v[i] = v._v[i];
		};

		/*
		** Iterations
		*/

		Iterator begin()
		{
			Iterator b;

			b._t = &_v[0];
			return (b);
		};

		Iterator end()
		{
			Iterator b;

			b._t = &_v[_size];
			return (b);
		};

		Iterator rbegin()
		{
			Iterator b;

			b._t = &_v[-1];
			return (b);
		};

		Iterator rend()
		{
			Iterator b;

			b._t = &_v[_size - 1];
			return (b);
		};
		/*
		** ACCESS
		** Don't forget to throw the out of range exception
		*/
		T& operator [] (size_type i)
		{
			return (_v[i]);
		};

		const T& operator [] (size_type i) const
		{
			return (_v[i]);
		};

		T& front()
		{
			return (_v[0]);
		};

		const T& front() const
		{
			return (_v[0]);
		};

		T& back()
		{
			return (_v[_size - 1]);
		};

		const T& back() const
		{
			return (_v[_size - 1]);
		};

		T& at(size_t i)
		{
			return (_v[i]);
		};

		const T& at(size_t i) const
		{
			return (_v[i]);
		};

		/*
		** CAPACITY
		** waht is maX_size??
		*/
		bool	empty()
		{
			return (_size == 0);
		};

		size_type size()
		{
			return (_size);
		};

		size_type	capacity()
		{
			return (_capacity_size);
		};

		difference_type max_size()
		{
			return (std::numeric_limits<difference_type>::max());
		};

		/*
		** MODIFIERS
		*/

		void clear() // not sure
		{
			_size = 0;
		};

		void push_back(T t)
		{
			if (_capacity_size > _size + 1)
			{
				_v[_size] = t;
				_size += 1;
				return ;
			}
			T* b;
			_capacity_size = _size + CAPACITY;
			b =_allocator.allocate(_capacity_size);

			for (size_type i = 0; i < _size; i++)
				b[i] = _v[i];
			b[_size] = t;
			_allocator.deallocate(_v, _size);
			_v = b;
			_size += 1;
		};

		void pop_back()
		{
			if (!empty())
				_size -= 1;
		};

		void reserve(size_type new_cap)
		{
			if (new_cap <= _capacity_size)
				return ;
			T*	b;
			b = _allocator.allocate(new_cap);
			for (int i = 0; i < _size; i++)
				b[i] = _v[i];
			_allocator.deallocate(_v, _capacity_size);
			_capacity_size = new_cap;
			_v = b;
		};

		void resize(size_type count, T value = T())
		{
			T*	b;

			if (_size >= count)
			{
				_size = count;
				return ;
			}
			if (count <= _capacity_size)
			{
				for (int i = _size; i < count; i++)
					_v[i] = value;
				_size = count;
			}
			else
			{
				b = _allocator.allocate(count + CAPACITY);
				for (int i = 0; i < _size; i++)
					b[i] = _v[i];
				for (int i = _size; i < count; i++)
					b[i] = value;
				_size = count;
				_allocator.deallocate(_v, _capacity_size);
				_capacity_size = count + CAPACITY;
				_v = b;
			}
		};

		Iterator insert(Iterator pos)
		{
			
		};

		Iterator insert(Iterator start, Iterator last)
		{

		};

		void 	erase(Iterator pos)
		{
			difference_type diff = pos - begin();

			for (int i = diff; i < _size - 1; i++)
			{
				_v[i] = _v[i + 1];
			}
			_size -= 1;
		};

		void 	erase(Iterator start, Iterator last) // check errors ?
		{
			difference_type diff = start - begin();

			for (int i = diff; last != end(); i++, last++)
			{
				_v[i] = *last;
			}
			_size -= last - start;
		};

		private:
		T*				_v;
		size_type 			_size;
		size_type		_capacity_size;
		Allocator 		_allocator;
	};
};
