#ifndef MAP_HPP
#define MAP_HPP


#include <cstddef>
#include <limits>
#include "BST.hpp"
#include "../utils/Reverse_Iterator.hpp"
#include "../utils/Utils.hpp"



namespace ft
{

	/*template<typename Key, typename T>
	*/

	template<class Key, class T, class Compare = Less<Key>,
	class Allocator = Allocator<Pair<const Key,T> > >
	class Map
	{
		public:
		typedef Key key_type;
		typedef typename BST<Key,T,Compare,Allocator>::Iterator iterator;
		typedef typename BST<Key,T,Compare,Allocator>::const_iterator const_iterator;
		typedef typename BST<Key,T,Compare,Allocator>::reverse_iterator reverse_iterator;
		typedef typename BST<Key,T,Compare,Allocator>::const_reverse_iterator const_reverse_iterator;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef size_t	size_type;
		typedef ptrdiff_t difference_type;
		typedef Pair<const Key,T> value_type;
		typedef value_type& reference;
		typedef const Pair<const Key, T>& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;

		protected:
		struct Value_Compare
		{
			bool operator()(const_reference x, const_reference y)
			{
				return (x.first < y.first);
			}
		};

		public:
		typedef Value_Compare value_compare;

		Map()
		{
		}

		template<typename input_iteraror>
		Map(input_iteraror first, input_iteraror last)
		{
			while (first != last)
			{
				_bst.insert(*first);
				++first;
			}
		}

		Map(const Map& map)
		{
			_bst = map._bst;
		}

		void operator = (const Map& map)
		{
			_bst = map._bst;
		}

		~Map()
		{

		}

		/*
		** CAPACITY
		*/

		bool empty() const
		{
			return (_bst.size() == 0);
		}

		size_type size() const
		{
			return (_bst.size());
		}

		size_type max_size() const
		{
			// to implement
			//std::cout << "ici: " << sizeof(std::pair<Key, T>) << std::endl;
			// c'est sizeof(pair<key, T> + n * pointeurs dans la struct)
			return (std::numeric_limits<size_type>::max() / (sizeof(value_type) + 4 * 8));
		}

		/*
		** Access
		*/

		T& operator [] (const key_type& key)
		{
			return (_bst.search(key));
		}

		/*
		** Modifiers
		** Untested yet
		*/

		Pair<iterator,bool> insert(const value_type& val)
		{
			size_type size = _bst.size();
			_bst.insert(val);
			return (Pair<iterator,bool>(_bst.find(val.first), (size < _bst.size())));
		} // two more inserts to do

		iterator insert(iterator pos, const value_type& val)
		{
			(void)pos; // just a hint that i ignore right now
			_bst.insert(val);
			return (_bst.find(val.first));
		}

		template<typename input_iterator>
		void insert(input_iterator first, input_iterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		size_type erase(const key_type& key)
		{
			size_type size = _bst.size();
			_bst.delete_key(key);
			return (size - _bst.size());
		} // two more to go

		void erase(iterator pos)
		{
			// ignoring the iterator for now
			_bst.delete_key(pos->first);
		}

		void erase(iterator first, iterator last)
		{
			iterator b;

			while (first != last)
			{
				b = first;
				b++;
				_bst.delete_key((*first).first);
				first = b;
				if (first == end())
					return ;
			}
		}

		void swap(Map& map)
		{
			_bst.swap(map._bst);
		}

		void clear()
		{
			_bst.clear();
		}

		iterator find(const key_type& key)
		{
			return (_bst.find(key));
		}

		const_iterator find(const key_type& key) const
		{
			return (_bst.find(key));
		}

		size_type count(const key_type& key) const
		{
			if (_bst.find(key) != _bst.end())
				return (1);
			else
				return (0);
		}

		iterator lower_bound(const key_type& key)
		{
			for (iterator end = _bst.end(), it = _bst.begin(); it != end; it++)
			{
				if (!_comp((*it).first, key))
					return (it);
			}
			return (_bst.end());
		}

		const_iterator lower_bound(const key_type& key) const
		{
			for (iterator end = _bst.end(), it = _bst.begin(); it != end; it++)
			{
				if (!_comp((*it).first, key))
					return (it);
			}
			return (_bst.end());
		}

		iterator upper_bound(const key_type& key)
		{
			for (iterator end = _bst.end(), it = _bst.begin(); it != _bst.end(); it++)
			{
				if (_comp(key, (*it).first))
					return (it);
			}
			return (_bst.end());
		}

		const_iterator upper_bound(const key_type& key) const
		{
			for (iterator end = _bst.end(), it = _bst.begin(); it != _bst.end(); it++)
			{
				if (_comp(key, (*it).first))
					return (it);
			}
			return (_bst.end());
		}

		Pair<iterator,iterator> equal_range(const key_type& key)
		{
			return (Pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}

		Pair<const_iterator,const_iterator> equal_range(const key_type& key) const
		{
			return (Pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}


		/*
		** Members stuff
		*/

		key_compare key_comp() const
		{
			return (_comp);
		}

		value_compare value_comp() const
		{
			return (_value_comp);
		}

		/*value_comp value_comp() const
		{
			return (_value_comp);
			Create the struct value_comp
		}*/

		/*
		** Iterator stuff
		*/

		iterator begin()
		{
			return (_bst.begin());
		}

		const_iterator begin() const
		{
			return (_bst.begin());
		}

		iterator end()
		{
			return (_bst.end());
		}

		const_iterator end() const
		{
			return (_bst.end());
		}

		reverse_iterator rbegin()
		{
			return (_bst.rbegin());
		}

		reverse_iterator rend()
		{
			return (_bst.rend());
		}

		const_reverse_iterator rbegin() const
		{
			return (_bst.rbegin());
		}

		const_reverse_iterator rend() const
		{
			return (_bst.rend());
		}

		/*
		** OBSERVERS
		*/

		private:
		BST<Key,T,Compare,Allocator>	_bst;
		allocator_type 					_allocator;
		key_compare 					_comp;
		value_compare					_value_comp;
	};
};


#endif
