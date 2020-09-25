#ifndef MAP_HPP
#define MAP_HPP

#include "BST.hpp"

/*
** Needto do the iterate stuffs
** maybe unspecialised BST that take a pair
** see std::less for testing equality
** Value comp, key comp
*/

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:
		typedef Key key_type;
		typedef typename BST<Key,T,Compare,Allocator>::Iterator iterator;
		typedef typename BST<Key,T,Compare,Allocator>::const_iterator const_iterator;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef size_t	size_type;
		typedef ptrdiff_t difference_type;
		typedef std::pair<Key,T> value_type;

		public:
		Map()
		{
		}

		template<typename input_iteraror>
		Map(input_iteraror first, input_iteraror last)
		{
			while (first != last)
			{
				_bst.insert(*first);
				first++;
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
			return (42);
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

		std::pair<iterator,bool> insert(const value_type& val)
		{
			size_type size = _bst.size();
			_bst.insert(val);
			return (std::make_pair(_bst.find(val.first), (size < _bst.size())));
		} // two more inserts to do

		size_type erase(const key_type& key)
		{
			size_type size = _bst.size();
			_bst.delete_key(key);
			return (size - _bst.size());
		} // two more to go

		void erase(iterator pos)
		{
			// ignoring the iterator for now
			_bst.delete_key(pos.first);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				_bst.delete_key((*first).first);
				first++;
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
			for (iterator end = _bst.end(), it = _bst.begin(); it != end(); it++)
			{
				if (!_comp((*it).first, key))
					return (it);
			}
			return (_bst.end());
		}

		iterator upper_bound(const key_type& key)
		{
			for (iterator end = _bst.end(), it = _bst.begin(); it != end(); it++)
			{
				if (_comp(key, (*it).first))
					return (it);
			}
			return (_bst.end());
		}

		std::pair<iterator,iterator> equal_range(const key_type& key)
		{
			return (std::make_pair(lower_bound(key), upper_bound(key)));
		}

		/*
		** Members stuff
		*/

		key_compare key_comp() const
		{
			return (_comp);
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

		iterator rbegin()
		{
			return (_bst.rbegin());
		}

		iterator rend()
		{
			return (_bst.rend());
		}

		private:
		BST<Key,T,Compare,Allocator>	_bst;
		allocator_type 					_allocator;
		key_compare 					_comp;
	};
};


#endif
