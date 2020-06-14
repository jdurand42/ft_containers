#include "BST.hpp"

int main()
{
	ft::BST<int,std::string> bst;

	std::pair<int,std::string> pair;

	bst.insert(std::make_pair(10, "richard"));
	bst.insert(std::make_pair(15, "richard15"));
	bst.insert(std::make_pair(16, "richard16"));
	bst.insert(std::make_pair(13, "richard13"));
	bst.insert(std::make_pair(3, "richard3"));
	bst.insert(std::make_pair(5, "richard5"));
	bst.insert(std::make_pair(6, "richard6"));

	std::cout << bst.search(10) << std::endl;
	std::cout << bst.search(15) << std::endl;
	std::cout << bst.search(16) << std::endl;
	std::cout << bst.search(13) << std::endl;
	std::cout << bst.search(3) << std::endl;
	std::cout << bst.search(5) << std::endl;
	std::cout << bst.search(6) << std::endl;
	bst.inorder();

/*	bst.delete_key(13);
	bst.delete_key(16);
	bst.delete_key(10);
*/
std::cout << "ici" << std::endl;
	bst.inorder();
	bst.iterate(0);
	std::cout << "ici" << std::endl;
	for (int i = 0; i < 8; i++)
		bst.iterate(i);


}
