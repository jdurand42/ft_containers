#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include "List.hpp"

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

		bool empty()
		{
			return (_stack.empty());
		}

		size_type size()
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
}

#endif
