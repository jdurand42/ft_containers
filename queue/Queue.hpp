#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include "../list/List.hpp"

/*
** Don't forget to do relationnal operators
** And the other CONSTRUCTORS
*/

namespace ft
{
	template <class T, class Container = List<T> >
	class queue
	{
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		queue()
		{

		};

		queue(const queue& queue) // not sure about that
		{
			_queue = queue._queue;
		};

		void operator = (const queue& queue)
		{
			_queue = queue._queue;
		};

		queue(const container_type& container)
		{
			_queue = container;
		};

		~queue()
		{

		};

		bool empty()
		{
			return (_queue.empty());
		}

		size_type size()
		{
			return (_queue.size());
		}

		T& back()
		{
			return (_queue.back());
		}

		const T& back() const
		{
			return (_queue.back());
		}

		T& front()
		{
			return (_queue.front());
		}

		const T& front() const
		{
			return (_queue.front());
		}

		void push(T value)
		{
			_queue.push_back(value);
		}

		void pop()
		{
			_queue.pop_front();
		}

		private:
		Container _queue;
	};
}

#endif
