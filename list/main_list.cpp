#include "List.hpp"
#include <list>

int main()
{
	int a;

	ft::List<std::string> list2(15, "henrichard");
	std::cout << list2.front() << std::endl;
	std::cout << list2.back() << std::endl;
	std::cout << list2.size() << std::endl;

	ft::List<int> list3(10, 50);
	std::cout << list3.front() << std::endl;
	std::cout << list3.back() << std::endl;
	std::cout << list3.size() << std::endl;

	ft::List<int> list(4, 42);
	std::cout << "empty?: " << list.empty() << std::endl;
		std::cout << std::endl;
	list.push_front(12);
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	list.push_front(24);
		std::cout << std::endl;
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	list.push_back(25);
		std::cout << std::endl;
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;

//	list.clear();
	std::cout << list.size() << std::endl;

	ft::List<int> list5(1, 42);
	std::cout << "la\n";
	std::cout << list5.front() << std::endl;
	std::cout << list5.back() << std::endl;
	std::cout << list5.size() << std::endl;


std::cout << std::endl;std::cout << std::endl;std::cout << std::endl;
	std::list<std::string> b(5, "lol");
	std::list<std::string>::iterator it = b.begin();
	std::list<std::string>::iterator it2 = b.end();
	while (it != it2)
	{
		std::cout << *it << '\n';
		it++;
	}
	//std::cout << *it << std::endl;
	//std::cout << *it2 << std::endl;

	/*std::cout << std::endl;
	list.pop_front();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;

	std::cout << std::endl;
	list.pop_front();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;

	std::cout << std::endl;
	list.pop_front();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;
	*/

	/*std::cout << std::endl;
	list.pop_back();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;

	std::cout << std::endl;
	list.pop_back();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << list.size() << std::endl;

	std::cout << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;*/
}
