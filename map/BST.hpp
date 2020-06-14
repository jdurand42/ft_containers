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
			}

			//private:
			/*Key				key;
			T			value;*/
			std::pair<Key,T> 	_pair;
			Node				*_left;
			Node				*_right;
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
			_root = insert(pair, _root);
		};

		Node* insert(std::pair<Key,T> pair, Node* node)
		{
		    if (node == NULL)
				return (new Node(pair));

		    if (pair.first < node->_pair.first)
		        node->_left  = insert(pair, node->_left);
		    else if (pair.first > node->_pair.first)
		        node->_right = insert(pair, node->_right);

		    return node;
		};

		void delete_key(Key key)
		{
			_root = delete_node(key, _root);
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

		void iterate(size_t idx)
		{
			if (_root != NULL)
		    {
				//Node *node;
				int c = 0;
				Node* node = iterate(_root, idx, &c);

				std::cout << node->_pair.first << ": " << node->_pair.second << std::endl;
		    }
		}

		Node *iterate(Node *node, int n, int *c)
		{
    		*c += 1;
    		while (*c <= n)
			{
				if (node->_left != NULL)
				{
            		node = iterate(node->_left, n, c);
        		}
        	//	*c += 1;
        		if (node->_right != NULL)
				{
            		node = iterate(node->_right, n, c);
				}
        	}
    		return node;
		}



		Node* delete_node(Key key, Node *node)
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
