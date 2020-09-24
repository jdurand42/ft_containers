#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include "../list/List.hpp"

/*
** Don't forget to do relationnal operators
*/

namespace ft
{
	template <class T, class Container = List<T> >
	class Stack
	{
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		Stack()
		{

		};

		Stack(const Stack& stack) // not sure about that
		{
			_stack = stack._stack;
		};

		void operator = (const Stack& stack)
		{
			_stack = stack._stack;
		};

		Stack(const container_type& container)
		{
			_stack = container;
		};

		~Stack()
		{

		};

		bool empty() const
		{
			return (_stack.empty());
		}

		size_type size() const
		{
			return (_stack.size());
		}

		T& top()
		{
			return (_stack.back());
		}

		const T& top() const
		{
			return (_stack.back());
		}

		void push(T value)
		{
			_stack.push_back(value);
		}

		void pop()
		{
			_stack.pop_back();
		}

		private:
		Container _stack;
	};
};


template <class T, class Container>
bool operator == (const ft::Stack<T,Container&> x, const ft::Stack<T,Container&> y)
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

template <class T, class Container>
bool operator != (const ft::Stack<T,Container>& x, const ft::Stack<T,Container>& y)
{
	return (!(x == y));
};

template <class T, class Container>
bool operator < (const ft::Stack<T,Container>& x, const ft::Stack<T,Container>& y)
{
	// check comportement on empty containers
	for (int i = 0, j = 0; i < x.size() && j < y.size(); i++, j++)
	{
		if (!(x[i] < y[i]))
			return (false);
	}
	return (true);
};

template <class T, class Container>
bool operator <= (const ft::Stack<T,Container>& x, const ft::Stack<T,Container>& y)
{
	// check comportement on empty containers
	for (int i = 0, j = 0; i < x.size() && j < y.size(); i++, j++)
	{
		if (!(x[i] <= y[i]))
			return (false);
	}
	return (true);
};

template <class T, class Container>
bool operator > (const ft::Stack<T,Container>& x, const ft::Stack<T,Container>& y)
{
	// check comportement on empty containers
	return (!(x < y));
};
template <class T, class Container>
bool operator >= (const ft::Stack<T,Container>& x, const ft::Stack<T,Container>& y)
{
	// check comportement on empty Container<T>s
	return (!(x <= y));
};

#endif
