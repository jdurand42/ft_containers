#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <limits>
#include "../list/List.hpp"


namespace ft
{
	template <class T, class Container = List<T> >
	class Queue
	{
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		Queue()
		{

		};

		Queue(const Queue& queue) // not sure about that
		{
			_queue = queue._queue;
		};

		void operator = (const Queue& queue)
		{
			_queue = queue._queue;
		};

		Queue(const container_type& container)
		{
			_queue = container;
		};

		~Queue()
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

		public:
		template <class Type, class Cont>
		friend bool operator == (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue == y._queue);
		};

		template <class Type, class Cont>
		friend bool operator != (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue != y._queue);
		};

		template <class Type, class Cont>
		friend bool operator < (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue < y._queue);
		};

		template <class Type, class Cont>
		friend bool operator <= (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue <= y._queue);
		};

		template <class Type, class Cont>
		friend bool operator > (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue > y._queue);
		};

		template <class Type, class Cont>
		friend bool operator >= (const ft::Queue<Type,Cont>& x, const ft::Queue<Type,Cont>& y)
		{
			return (x._queue >= y._queue);
		};

		template <class Type, class Cont>
		friend void swap(ft::Queue<Type,Cont>& x, ft::Queue<Type,Cont>& y);
	};

	template <class Type, class Cont>
	void swap(ft::Queue<Type,Cont>& x, ft::Queue<Type,Cont>& y)
	{
		return (x._queue.swap(y._queue));
	};

}

#endif
