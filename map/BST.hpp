#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

/*
** Recursive stuff
*/

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key,T> > >
	class BST
	{
		struct Node
		{
			public:
			Node(std::pair<Key,T> pair, Node *left = NULL, Node *right = NULL,
			Node *parent = NULL)
			{
				_pair = pair;
				_left = left;
				_right = right;
				_parent = parent;
			}

			std::pair<Key,T> 	_pair;
			Node				*_left;
			Node				*_right;
			Node				*_parent;
		};

		//typedef Key key_type;
		//typedef T mapped_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef size_t	size_type;

		class Iterator
		{
			Iterator(): _node(NULL)
			{
				_root = NULL;
			}

			private:
			Node	*_node;
//			Node	*_root;
		};

		public:
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

		Node *search_node(Key key, Node* node)
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
			if (node == NULL) // insert new key to default value
			{
				_root = insert(std::make_pair(key, T()), _root, NULL);
				return (search(key));
			}
	    	if (node->_pair.first == key)
	       		return (node->_pair.second);

	    	if (comp(node->_pair.first, key))//node->_pair.first < key)
				return (search(key, node->_right, node));

			return (search(key, node->_left, node));
		};

		void  insert(std::pair<Key,T> pair)
		{
			_root = insert(pair, _root, NULL);
		};

		Node* insert(std::pair<Key,T> pair, Node* node, Node *parent)
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

		        node->_pair.first = b->_pair.first;
				node->_pair.second = b->_pair.second;

		        node->_right = delete_node(b->_pair.first, node->_right);
		    }
		    return (node);
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
		allocator_type _allocator;
	};

};
#endif
