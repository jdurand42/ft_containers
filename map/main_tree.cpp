#include "BST.hpp"
#include <map>

int main()
{
	ft::BST<int,std::string> bst;

	std::pair<int,std::string> pair;

	bst.insert(std::make_pair(10, "10"));
	bst.insert(std::make_pair(15, "15"));
	bst.insert(std::make_pair(16, "16"));
	bst.insert(std::make_pair(13, "13"));
	bst.insert(std::make_pair(3, "3"));
	bst.insert(std::make_pair(5, "5"));
	bst.insert(std::make_pair(6, "6"));
	bst.insert(std::make_pair(2, "2"));
	bst.insert(std::make_pair(4, "4"));
	bst.insert(std::make_pair(4, "4"));
	bst.insert(std::make_pair(4, "4"));

	std::cout << bst.search(10) << std::endl;
	std::cout << bst.search(15) << std::endl;
	std::cout << bst.search(16) << std::endl;
	std::cout << bst.search(13) << std::endl;
	std::cout << bst.search(3) << std::endl;
	std::cout << bst.search(5) << std::endl;
	std::cout << bst.search(6) << std::endl;
	std::cout << bst.search(2) << std::endl;
	std::cout << bst.search(4) << std::endl;

	std::cout << "\nici" << std::endl;
	std::cout << "size: " << bst.size() << std::endl;


	ft::BST<int,std::string> bst2(bst);

	bst.search(5) = "lololol";
	bst.search(10) = "lololol";
	bst.search(3) = "lololol";
	bst.inorder();
	std::cout << "\ntest search, insert\n";
	std::cout << (bst.search(12) = "28") << std::endl;
	bst.inorder();
	std::cout << "size: " << bst.size() << std::endl;
	bst.delete_key(5);
	bst.delete_key(10);
	bst.delete_key(2);
	bst.inorder();
	std::cout << "size: " << bst.size() << std::endl;
	/*bst.delete_key(6);
	bst.delete_key(4);
	//bst.delete_key(6);*/

	std::cout << "\nici" << std::endl;
	bst2.search(5) = "lol";
	bst2.search(10) = "lol";
	bst2.search(3) = "lol";
	bst2.inorder();
	std::cout << bst2.search(4) << std::endl;

	std::cout << "\nTest on search to return Nodes\n";
	bst.get_node(12);
	bst.get_node(4);
	bst.get_node(6);
	bst.get_node(13);
	//bst.iterate(0);

	std::cout << "ici" << std::endl;
	bst2 = bst;
	bst2.inorder();

	bst2.clear();
	std::cout << "size: " << bst2.size() << std::endl;
	bst2.inorder();
	bst2.search(38);
	//bst2.insert(std::make_pair(35, "lol"));
	std::cout << "size: " << bst2.size() << std::endl;
	bst2.inorder();
	/*std::cout << "\n\n";
	std::map<std::string,int> map;
	map["bonjour"] = 125;
	std::cout << map["bonjour"] << "\n";
	std::cout << map["lol"] << std::endl;*/
	//for (int i = 0; i < 8; i++)
	//	bst.iterate(i);
	std::cout << "\nTest on std::less\n";
	std::less<int> less;
	std::cout << less(1, 2) << std::endl;
	std::cout << less(2, 1) << std::endl;
	std::cout << less(1, 1) << std::endl;

}
