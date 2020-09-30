#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>
#include "../Reverse_Iterator.hpp"
#include "../Utils.hpp"

/*
** Recursive stuff
*/

namespace ft
{
	template<class Key, class T, class Compare = Less<Key>,
	class Allocator = Allocator<Pair<const Key,T> > >
	class BST
	{

		// class input_iterator Iterator;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef size_t	size_type;
		typedef Key key_type;
		typedef ptrdiff_t difference_type;
		typedef Pair<const Key, T> value_type;
		typedef value_type& reference;
		typedef const Pair<const Key, T>& const_reference;
		typedef const Pair<const Key,T>*	const_pointer;
		typedef Pair<const Key,T>* pointer;

		struct Node
		{
			public:
			Node()
			{
				_left = NULL;
				_parent = NULL;
				_right = NULL;
			}

			Node(const Node& node): _pair(node._pair)
			{
				_left = node._left;
				_right = node._right;
				_parent = node._parent;
			}

			void operator = (const Node& node)
			{
				_left = node._left;
				_right = node._right;
				_parent = node._parent;
				_pair = node._pair;
			}

			Node(value_type pair, Node *left = NULL, Node *right = NULL,
			Node *parent = NULL): _pair(pair)
			{
				//_pair = pair;
				_left = left;
				_right = right;
				_parent = parent;
			}

 			value_type 			_pair;
			Node				*_left;
			Node				*_right;
			Node				*_parent;
		};

		typedef typename Allocator::template rebind<Node>::other _node_allocator_type;

		public:
		class Iterator
		{
			// Root initialised with BST methods
			public:
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef Pair<const Key,T>*			pointer;
			typedef Pair<const Key,T>&			reference;
			typedef Pair<const Key,T> value_type;
			typedef const Pair<const Key,T>&	const_reference;
			typedef const Pair<const Key,T>*	const_pointer;


			Iterator()
			{
				_node = NULL;
				_root = NULL;
			}

			Iterator(Node* node, Node *root)
			{
				_node = node;
				_root = root;
			}

			Iterator(const Iterator& it)
			{
				_node = it._node;
				_root = it._root;
			}

			void operator = (const Iterator& it)
			{
				_node = it._node;
				_root = it._root;
			}

			~Iterator()
			{

			}

			Pair<const Key,T>& operator * ()
			{
				return (_node->_pair);
			}

			Pair<const Key,T>* operator -> ()
			{
				return (&_node->_pair);
			}

			bool operator == (const Iterator& it) const
			{
				return (_node == it._node);
			}

			bool operator != (const Iterator& it) const
			{
				return (!(_node == it._node));
			}

			Iterator& operator ++ ()
			{
				if (_node && _node->_right)
				{
					_node = _node->_right;
					while (_node->_left)
						_node = _node->_left;
				}
				else if (_node && _node->_parent && _node == _node->_parent->_left)
				{
					_node = _node->_parent;
				}
				else if (_node && _node->_parent && _node->_parent->_right == _node)
				{
					Node *b = _node;

					while (_node && b != _node->_left)
					{
						b = _node;
						_node = _node->_parent;
					}

				}
				else
				{
					Node *b1 = _node;
					Node *b2 = _node;

					if (_node && !_node->_right)
					{
						if (!_node->_parent)
						{

							_node = NULL;
							return (*this);
						}
						else
						{
							b1 = _node;
							b2 = _node->_parent;
							while (b2->_right == b1)
							{
								b1 = b2;
								b2 = b1->_parent;
								if (b2 == NULL)
								{
									_node = NULL;
									return (*this);
								}
							}
						}
					}
					_node = _root;
					while (_node && _node->_left)
						_node = _node->_left;
				}
				return (*this);
			}

			Iterator operator ++ (int)
			{
				Iterator it = *this;
				operator++();
				return (it);
			}

			Iterator& operator -- ()
			{
				if (_node && _node->_left)
				{
					_node = _node->_left;
					while (_node && _node->_right)
						_node = _node->_right;
				}
				else if (_node)
				{
					Node *b = _node;
					while (_node && b != _node->_right)
					{
						b = _node;
						_node = _node->_parent;
					}
				}
				else
				{
					Node *b1 = _node;
					Node *b2 = _node;

					if (_node && !_node->_left)
					{
						if (!_node->_parent)
						{

							_node = NULL;
							return (*this);
						}
						else
						{
							b1 = _node;
							b2 = _node->_parent;
							while (b2->_left == b1)
							{
								b1 = b2;
								b2 = b1->_parent;
								if (b2 == NULL)
								{
									_node = NULL;
									return (*this);
								}
							}
						}
					}

					_node = _root;
					while (_node && _node->_right)
						_node = _node->_right;
				}
				return (*this);
			}

			Iterator operator -- (int)
			{
				Iterator it = *this;
				operator--();
				return (it);
			}

			protected:
			Node	*_node;
			Node	*_root;
		};

		class Const_Iterator: public Iterator
		{
			public:
			Const_Iterator(): Iterator()
			{
			}

			Const_Iterator(const Const_Iterator& i): Iterator(i)
			{}

			Const_Iterator(const Iterator& i): Iterator(i)
			{}

			Const_Iterator(Node *node, Node *root): Iterator(node, root)
			{};

			void operator = (const Const_Iterator& i)
			{
				Iterator::_node = i._node;
				Iterator::_root = i._root;
			}

			virtual ~Const_Iterator() {};

			Const_Iterator(T* t): Iterator(t)
			{}

			const_reference operator * ()
			{
				//std::cout << "bonjour";
				return (Iterator::_node->_pair);
			};

			const_pointer operator -> ()
			{
				return (&Iterator::_node->_pair);
			};

	//		pointer get_addr() // trés moche
	//		{
	//			return (&Iterator::_node->_pair);
	//		};
		};

		class Const_Reverse_Iterator: public Reverse_Iterator<Iterator>
		{
			public:
			Const_Reverse_Iterator() {};
			Const_Reverse_Iterator(const Iterator& i): Reverse_Iterator<Iterator>(i)
			{};
			Const_Reverse_Iterator(const Const_Reverse_Iterator& i): Reverse_Iterator<Iterator>(i)
			{};
			Const_Reverse_Iterator(const Reverse_Iterator<Iterator>& i): Reverse_Iterator<Iterator>(i)
			{};
			void operator = (const Reverse_Iterator<Iterator>& i)
			{
				Reverse_Iterator<Iterator>::_base = i._base;
			}

			const_reference operator * () const
			{
				const_iterator a = Reverse_Iterator<Iterator>::_base;
				return (*a);
			//	return (*_base);
			};

			const_pointer operator -> () const
			{
				const_iterator a = Reverse_Iterator<Iterator>::_base;
				const_pointer cp = a.operator->();
				return (cp);
			};
		};

		typedef Iterator iterator;
		typedef Reverse_Iterator<Iterator> reverse_iterator;
		typedef Const_Iterator const_iterator;
		typedef Const_Reverse_Iterator const_reverse_iterator;

		BST()
		{
			_root = NULL;
			_size = 0;
		}

		BST(const BST& bst)
		{
			// la flemme;
			_root = bst.copy_tree();
			_size = bst._size;
		};

		void operator = (const BST& bst)
		{
			// la flemme aussi
			clear();
			_root = bst.copy_tree();
			_size = bst._size;
		};

		~BST()
		{
			clear();
		}

		Node *copy_tree() const
		{
			return (copy_tree(_root, NULL));
		}

		Node *copy_tree(Node *root, Node *parent) const
		{
			if (!root)
				return (NULL);
			//Node *node = _allocator.allocate(1);
			//_allocator.construct(node, Node(root->_pair, NULL, NULL, parent));
			Node *node = new Node(root->_pair, NULL, NULL, parent);
			node->_left = copy_tree(root->_left, node);
			node->_right = copy_tree(root->_right, node);
			return (node);
		}

		void clear()
		{
			while (_root)
			{
				delete_key(_root->_pair.first);
			}
			_root = NULL;
		}

		Node* get_node(Key key)
		{
			Node *node = search_node(key, _root);
			return (node);
			/*if (node)
				std::cout << "Node found: " << node->_pair.first << " " << node->_pair.second
				<< std::endl;*/
		}

		Node *search_node(Key key, Node* node) const
		{
			if (node == NULL) // insert new key to default value
			{
				//insert(std::make_pair(key, T()), _root, NULL);
				return (NULL);
			}
			if (node->_pair.first == key)
				return (node);

			if (comp(node->_pair.first, key))//node->_pair.first < key)
				return (search_node(key, node->_right));

			return (search_node(key, node->_left));
		}

		T& search(Key key)
		{
			return (search(key, _root, NULL));
		}

		T& search(Key key, Node *node, Node *parent)
		{
			(void)parent;
			if (node == NULL) // insert new key to default value
			{
				_root = insert(value_type(key, T()), _root, NULL);
				return (search(key));
			}
	    	if (node->_pair.first == key)
	       		return (node->_pair.second);

	    	if (comp(node->_pair.first, key))//node->_pair.first < key)
				return (search(key, node->_right, node));

			return (search(key, node->_left, node));
		};

		void  insert(value_type pair)
		{
			_root = insert(pair, _root, NULL);
		};

		Node* insert(value_type pair, Node* node, Node *parent)
		{
		    if (node == NULL)
			{
				Node *new_node = new Node(pair);
				new_node->_parent = parent;
				_size += 1;
				return (new_node);
			}

		    if (comp(pair.first, node->_pair.first))//pair.first < node->_pair.first)
		        node->_left  = insert(pair, node->_left, node);
		    else if (!comp(pair.first, node->_pair.first) && pair.first != node->_pair.first)//pair.first > node->_pair.first)
		        node->_right = insert(pair, node->_right, node);

		    return node;
		};

		Node *min_value_node(Node* node)
		{
		    Node* b = node;

		    while (b && b->_left != NULL)
		        b = b->_left;
		    return (b);
		}

		void inorder() // Functions utils for testing/printing the tree, to be removed
		{
			if (_root)
				inorder(_root);
		}

		void inorder(Node *node)
		{
		    if (node != NULL)
		    {
		        inorder(node->_left);
		        std::cout << node->_pair.first << ": " << node->_pair.second;
				if (node->_parent)
					std::cout << " |||| Parent: " << node->_parent->_pair.first << " " << node->_parent->_pair.second
					<< std::endl;
				else
					std::cout << " ||| Parent: None\n";
		        inorder(node->_right);
		    }
		}

		void delete_key(Key key)
		{
			_root = delete_node(key, _root);
		}

		Node* delete_node(Key key, Node *node) // put parent in here
		{
		    // base case
		    if (node == NULL)
				return (node);

		    if (key < node->_pair.first)
		        node->_left = delete_node(key, node->_left);

		    else if (key > node->_pair.first)
		        node->_right = delete_node(key, node->_right);

		    else
		    {
		        if (node->_left == NULL)
		        {
		            Node *b = node->_right;
		            free(node);
					_size -= 1;
		            return (b);
		        }
		        else if (node->_right == NULL)
		        {
		            Node *b = node->_left;
		            free(node);
					_size -= 1;
		            return (b);
		        }
		      Node* b = min_value_node(node->_right);
			  Node *right = node->_right;
			  Node *left = node->_left;
			  Node *parent = node->_parent;
			  free(node);
			  node = new Node(value_type(b->_pair.first, b->_pair.second), left, right, parent);
			  //node->_pair.first = b->_pair.first;
			  //node->_pair.second = b->_pair.second;
			  node->_right = delete_node(b->_pair.first, node->_right);
		    }
		    return (node);
		}

		/*
		** Iterations
		*/
		Iterator begin()
		{
			Node *node = _root;

			while (node && node->_left)
				node = node->_left;
			return (Iterator(node, _root));
		}

		const_iterator begin() const
		{
			Node *node = _root;

			while (node && node->_left)
				node = node->_left;
			return (const_iterator(node, _root));
		}

		Iterator end()
		{

		//	it._root = _root;
		//	it._node = NULL;
			//while (it._node && it._node->_right)
			//	it._node = it._node._right;
			// or return (_null)
			return (Iterator(NULL, _root));
		}

		const_iterator end() const
		{

		//	it._root = _root;
		//	it._node = NULL;
			//while (it._node && it._node->_right)
			//	it._node = it._node._right;
			// or return (_null)
			return (const_iterator(NULL, _root));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(Iterator(--end())));
		}

		reverse_iterator rend()
		{
			Node *node = _root;

			while (node && node->_right)
				node = node->_right;
			return (reverse_iterator(Iterator(--begin())));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(Iterator(--end())));
		}

		const_reverse_iterator rend() const
		{
			Node *node = _root;

			while (node && node->_right)
				node = node->_right;
			return (const_reverse_iterator(Iterator(--begin())));
		}


		Iterator find(const Key& key) const
		{
//			Iterator it;

//			it._root = _root;

			Node *node = search_node(key, _root);
			if (node)
				return (Iterator(node, _root));
			else
				return (end());
		}

		void swap(BST& bst)
		{
			Node *b;
			b = _root;
			_root = bst._root;
			bst._root = b;

			size_type size;
			size = _size;
			_size = bst._size;
			bst._size = size;
		}

		/*
		** CAPACITY
		*/

		size_type size() const
		{
			return (_size);
		}

		private:
		Node *_root;
		size_type _size;
		key_compare comp;
		_node_allocator_type _allocator;
	};

};
#endif
