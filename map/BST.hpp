#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

namespace ft
{
	template<class Key, class T>
	class BST
	{
		struct Node
		{
			public:
			Node(std::pair<Key,T> pair)
			{
				_pair = pair;
				_left = NULL;
				_right = NULL;
				_parent = NULL;
			}

			//private:
			/*Key				key;
			T			value;*/
			std::pair<Key,T> 	_pair;
			size_t				_i;
			Node				*_left;
			Node				*_right;
			Node				*_parent;
		};

		public:
		BST()
		{
			_root = NULL;
		}

		BST(const BST& bst)
		{
			// la flemme;
		};

		void operator = (const BST& bst)
		{
			// la flemme aussi
		};

		~BST()
		{
			while (_root)
			{
				delete_key(_root->_pair.first);
			}
		}

		T& search(Key key)
		{
			return (search(key, _root));
		}

		T& search(Key key, Node *node)
		{
			if (node == NULL)
				throw(std::out_of_range("Exception: Key not found"));
	    	if (node->_pair.first == key)
	       		return (node->_pair.second);

	    	if (node->_pair.first < key)
				return (search(key, node->_right));

			return (search(key, node->_left));
		};

		void  insert(std::pair<Key,T> pair)
		{
			_root = insert(pair, _root, NULL);
			int i = 0;
		};

		Node* insert(std::pair<Key,T> pair, Node* node, Node *parent)
		{
		    if (node == NULL)
			{
				Node *new_node = new Node(pair);
				new_node._parent = parent;
				return (new_node;
			}

		    if (pair.first < node->_pair.first)
		        node->_left  = insert(pair, node->_left, node);
		    else if (pair.first > node->_pair.first)
		        node->_right = insert(pair, node->_right, node);

		    return node;
		};

		void delete_key(Key key)
		{
			_root = delete_node(key, _root);
			int i = 0;
		}

		Node *min_value_node(Node* node)
		{
		    Node* b = node;

		    while (b && b->_left != NULL)
		        b = b->_left;
		    return (b);
		}

		void inorder()
		{
			if (_root)
				inorder(_root);
		}

		void inorder(Node *node)
		{
		    if (node != NULL)
		    {
		        inorder(node->_left);
		        std::cout << node->_pair.first << ": " << node->_pair.second <<std::endl;
		        inorder(node->_right);
		    }
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
		            return (b);
		        }
		        else if (node->_right == NULL)
		        {
		            Node *b = node->_left;
		            free(node);
		            return (b);
		        }
		        Node* b = min_value_node(node->_right);

		        node->_pair.first = b->_pair.first;
				node->_pair.second = b->_pair.second;

		        node->_right = delete_node(b->_pair.first, node->_right);
		    }
		    return (node);
		}

		private:
		Node *_root;

	};

};
#endif
