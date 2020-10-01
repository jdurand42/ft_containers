#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <limits>
#include "../list/List.hpp"

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

		public:
		template <class Type, class Cont>
		friend bool operator == (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack == y._stack);
		};

		template <class Type, class Cont>
		friend bool operator != (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack != y._stack);
		};

		template <class Type, class Cont>
		friend bool operator < (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack < y._stack);
		};

		template <class Type, class Cont>
		friend bool operator <= (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack <= y._stack);
		};

		template <class Type, class Cont>
		friend bool operator > (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack > y._stack);
		};

		template <class Type, class Cont>
		friend bool operator >= (const ft::Stack<Type,Cont>& x, const ft::Stack<Type,Cont>& y)
		{
			return (x._stack >= y._stack);
		};

		template <class Type, class Cont>
		friend void swap(ft::Stack<Type,Cont>& x, ft::Stack<Type,Cont>& y);
	};

	template <class Type, class Cont>
	void swap(ft::Stack<Type,Cont>& x, ft::Stack<Type,Cont>& y)
	{
		return (x._stack.swap(y._stack));
	};


};
#endif
