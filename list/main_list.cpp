#include "List.hpp"
#include <list>

int main()
{
	//ft::List<int> list1;
	ft::List<int> list1(10, 42);
	std::cout << list1.front() << " " << list1.back() << std::endl;
	std::cout << list1.size() << std::endl;

	std::cout << "Access: " << list1[0] << " " << list1[5] << " " << list1[9] << " " << std::endl;
	std::cout << "Access: " << list1[1] << " " << list1[2] << " " << list1[8] << " " << std::endl;
	list1[0] = 18;
	list1[9] = 25;
	std::cout << list1[2] << " " << list1[3] << " " << list1.front() << " " << list1.back() << std::endl;

	ft::List<int> list2(list1);


	std::cout << "Access: " << list2[0] << " " << list2[5] << " " << list2[9] << " " << std::endl;
	std::cout << "Access: " << list2[1] << " " << list2[2] << " " << list2[8] << " " << std::endl;
	list2[0] = 18;
	list2[9] = 25;
	std::cout << list2[2] << " " << list2[3] << " " << list2.front() << " " << list2.back() << std::endl;
	list2.pop_front();
	list2.pop_back();
	std::cout << list2.front() << " " << list2.back() << std::endl;
	std::cout << list2.size() << std::endl;
	while (list2.size() > 1)
		list2.pop_front();
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;
	list2[0] = 162;
	std::cout << "ici\n";
	std::cout << list2.front() << " " << list2.back() << std::endl;
	list2.resize(25, 72);
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;
	std::cout << list2[24] << " ";
	std::cout << list2[0] << " ";
	std::cout << list2[12] << std::endl;
	list2.resize(21, 72);
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;
	std::cout << list2[20] << " ";
	std::cout << list2[0] << " ";
	std::cout << list2[12] << std::endl;

	std::cout << "assign:  |||" << std::endl;
	list2.assign(50, 125);
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;
	std::cout << list2[49] << " ";
	std::cout << list2[0] << " ";
	std::cout << list2[12] << std::endl;


	std::cout << "\nRemove ||\n";
	list2.remove(2);
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;

	list2[49] = 130;
	list2[48] = 130;
	list2[47] = 130;

/*	list2.remove(125);*/
	list2.unique();
		std::cout << list2.size() << std::endl;
	list2.unique();
	std::cout << list2.size() << std::endl;
	std::cout << list2.front() << " " << list2.back() << std::endl;

	std::cout << "\nEntering the sorting stuff||||\n";

	int myints[] = {16, 34, 23, 1, 28};
	ft::List<int> list_ordered(myints, myints + 5);
	for (int i = 0; i < list_ordered.size(); i++)
		std::cout << list_ordered[i] << " ";
	std::cout << std::endl;
	list_ordered.sort();

	for (int i = 0; i < list_ordered.size(); i++)
		std::cout << list_ordered[i] << " ";
	std::cout << std::endl;
	list_ordered.merge(list1);

	for (int i = 0; i < list_ordered.size(); i++)
		std::cout << list_ordered[i] << " ";
	std::cout << std::endl;

	list_ordered.reverse();

	for (int i = 0; i < list_ordered.size(); i++)
		std::cout << list_ordered[i] << " ";
	std::cout << std::endl;
/*	std::cout << list2[2] << " ";
	std::cout << list2[0] << " ";
	std::cout << list2[1] << std::endl;*/

	/*int myints[] = {1, 2, 3, 4, 5};
	ft::List<int> list3(myints, myints + 5);
	std::cout << list3.size() << std::endl;
	std::cout << list3.front() << " " << list3.back() << std::endl;
	std::cout << list3[4] << " ";
	std::cout << list3[0] << " ";
	std::cout << list3[2] << std::endl;*/

/*
	list2 = list1;


		std::cout << "Access: " << list2[0] << " " << list2[5] << " " << list2[9] << " " << std::endl;
		std::cout << "Access: " << list2[1] << " " << list2[2] << " " << list2[8] << " " << std::endl;
		list2[0] = 18;
		list2[9] = 25;
		std::cout << list2[2] << " " << list2[3] << " " << list2.front() << " " << list2.back() << std::endl;*/
	/*list1.clear();
	std::cout << list1.size() << " " << list1.empty() << std::endl;*/
}
