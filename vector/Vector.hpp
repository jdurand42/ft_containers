#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include "../Reverse_Iterator.hpp"

#include <cmath>

/*
** everything is implemented
** Need to check return values, degree of protection agains't bad Iterators
** Need to stress it
** Need to throw outofrange exception and maybe, not permitted
** Need to check on reverse_iterator
** CONSTRUCTORS with iterators
** need to double check and test comparison operators
*/

namespace ft
{
	#define CAPACITY 5

	template<typename T, class Allocator = std::allocator<T> >
	class Vector
	{

		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef T			value_type;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;


		public:
		struct Iterator // random access iterator
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

			Iterator(T* t): _t(t)
			{}

			~Iterator() {};

			bool operator == (const Iterator& it) const
			{
				return (it._t == _t);
			};

			bool operator != (const Iterator& it) const
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

			difference_type operator - (Iterator it)
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

			bool operator < (const Iterator& it) const
			{
				return (_t < it._t);
			};

			bool operator <= (const Iterator& it) const
			{
				return (_t <= it._t);
			};

			bool operator > (const Iterator& it) const
			{
				return (_t > it._t);
			};

			bool operator >= (const Iterator& it) const
			{
				return (_t >= it._t);
			};

			private:
			T			*_t;
		};

		typedef Iterator	iterator;
		typedef Reverse_Iterator<iterator> reverse_iterator;

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

		Vector(size_type size, T value = T())
		{
			//v = new T[size + CAPACITY];
			_v = _allocator.allocate(CAPACITY + size);
			_size = size;
			_capacity_size = size + CAPACITY;

			for (size_t i = 0; i < _size; i++)
				_v[i] = value;
		};

		/*Vector(size_type size)
		{
			//v = new T[size + CAPACITY];
			_v = _allocator.allocate(CAPACITY + size);
			_size = size;
			_capacity_size = size + CAPACITY;
		};*/

		// NEED TO DO CONSTRUCTORS with an Array

	/*	Vector(T* first, T* last) // not tested yet
		{
			_v = _allocator.allocate(CAPACITY + last - first);
			_size = last - first;
			_capacity_size = _size + CAPACITY;

			while (first != last)
				push_back(*first++);
		};*/

		template<typename InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			_v = _allocator.allocate(CAPACITY + last - first);
			_size = last - first;
			_capacity_size = _size + CAPACITY;
			for (int i = 0; i < _size; i++, first++)
				_v[i] = *first;
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
			Iterator b(&_v[0]);

			//b._t = &_v[0];
			return (b);
		};

		Iterator end()
		{
			Iterator b(&_v[_size]);

			//b._t = &_v[_size];
			return (b);
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		};

 		reverse_iterator rend()
		{
			return (reverse_iterator(begin() - 1));
		};

		/*
		** ACCESS
		** Don't forget to throw the out of range exception
		*/
		T& operator [] (size_type i)
		{
			//if (i < 0 || i >= _size)
			//	throw (std::out_of_range("Index is out of range"));
			return (_v[i]);
		};

		const T& operator [] (size_type i) const
		{
			//if (i < 0 || i >= _size)
			//	throw (std::out_of_range("Index is out of range"));
			return (_v[i]);
		};

		T& at(size_type i)
		{
			if (i < 0 || i >= _size)
				throw (std::out_of_range(""));
			return (_v[i]);
		}

		const T& at (size_type i) const
		{
			if (i < 0 || i >= _size)
				throw (std::out_of_range(""));
			return (_v[i]);
		};

		T& front()
		{
			if (empty())
				throw(std::out_of_range("Vector empty, operation not permitted"));
			return (_v[0]);
		};

		const T& front() const
		{
			if (empty())
				throw(std::out_of_range("Vector empty, operation not permitted"));
			return (_v[0]);
		};

		T& back()
		{
			if (empty())
				throw(std::out_of_range("Vector empty, operation not permitted"));
			return (_v[_size - 1]);
		};

		const T& back() const
		{
			if (empty())
				throw(std::out_of_range("Vector empty, operation not permitted"));
			return (_v[_size - 1]);
		};

		/*
		** CAPACITY
		**
		*/
		bool	empty() const
		{
			return (_size == 0);
		};

		size_type size() const
		{
			return (_size);
		};

		size_type	capacity()
		{
			return (_capacity_size);
		};

		size_type max_size()  const
		{
			return ((std::pow(2, 64) / sizeof(T)));
		};

		void reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw(std::length_error(""));
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

		Iterator insert(Iterator pos, const T& value)
		{
			T* vb = new T[end() - pos];

			std::cout << "ici " << end() - pos << std::endl;
			for (int i = 0; i < end() - pos; i++)
				vb[i] = _v[pos - begin() + i];

			if (_size + 1 <= _capacity_size)
			{
				_v[pos - begin()] = value;
				_size += 1;
				for (int i = pos - begin() + 1, j = 0; i < _size; i++, j++)
					_v[i] = vb[j];
			}
			else
			{
				size_type vb_size = end() - pos;
				_size = pos - begin();
				push_back(value);
				for (int i = 0; i < vb_size; i++)
					push_back(vb[i]);
			}
			delete[] vb;
			return (pos);
		};

		Iterator insert(Iterator pos, size_type n, const T& value)
		{
			T* vb = new T[end() - pos];

			for (int i = 0; i < end() - pos; i++)
				vb[i] = _v[pos - begin() + i];

			if (_size + n <= _capacity_size)
			{
				for (int i = pos - begin(), j = 0; j < n; i++, j++)
					_v[i] = value;
				_size += n;
				for (int i = pos - begin() + n, j = 0; i < _size; i++, j++)
					_v[i] = vb[j];
			}
			else
			{
				size_type vb_size = end() - pos;
				_size = pos - begin();
				for (int i = 0; i < n; i++)
					push_back(value);
				for (int i = 0; i < vb_size; i++)
					push_back(vb[i]);
			}
			delete[] vb;
			return (pos);
		};

	/*	template<class InputIterator> // probleme dans l'overload -> try catch?
		Iterator insert(Iterator pos, InputIterator first, InputIterator last)
		{
						std::cout << "lollllll\n";
			return (pos);
		};*/

		Iterator 	erase(Iterator pos)
		{
			difference_type diff = pos - begin();

			for (int i = diff; i < _size - 1; i++)
			{
				_v[i] = _v[i + 1];
			}
			_size -= 1;
			return (pos + 1);
		};

		Iterator	erase(Iterator start, Iterator last) // check errors ?
		{
			difference_type diff = start - begin();

			difference_type length = last - start;

			for (int i = diff; last != end(); i++, last++)
				_v[i] = *last;
			_size -= length;
			return (begin() + diff + 1);
		};

		/*
		** FRIENDS
		*/
		friend void swap(Vector<T, Allocator>& x, Vector<T, Allocator>& y);
	/*	friend bool operator == (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);
		friend bool operator != (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);
		friend bool operator < (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);
		friend bool operator <= (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);
		friend bool operator > (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);
		friend bool operator >= (const Vector<T,Allocator>& x, const Vector<T,Allocator>& y);*/

		private:
		T*				_v;
		size_type 			_size;
		size_type		_capacity_size;
		Allocator 		_allocator;
	};

	template<typename T, class Allocator>
	void swap(Vector<T, Allocator>& x, Vector<T, Allocator>& y) // friend
	{
		Vector<T,Allocator> b = x;
		x = y;
		y = b;
	};
}

template <class T, class Allocator>
bool operator == (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
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
bool operator != (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
{
	return (!(x == y));
};

template <class T, class Allocator>
bool operator < (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
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
bool operator <= (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
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
bool operator > (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
{
	// check comportement on empty containers
	return (!(x < y));
};
template <class T, class Allocator>
bool operator >= (const ft::Vector<T,Allocator>& x, const ft::Vector<T,Allocator>& y)
{
	// check comportement on empty containers
	return (!(x <= y));
};

#endif
