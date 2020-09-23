VECTOR
LIST
MAP
STACK
QUEUE

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include "./containers.hpp"
#include "./utils/testers.hpp"

int announce
{
	std::string s;

	std::cout << "Choose a container to test:\n";
	std::cout << "1-Vector\n2-List\n3-Stack\n4-Queue\n5-Map\n6-Quit\n";
	std::getline(std::cin, s);
	//don't forget tot protect
	return (std::stoi(s));
}

int main()
{
	int choice;

	while ((choice = announce()) != 6)
	{
		if (choice == 1)
			test_vector();
		else if (choice == 2)
			test_list();
		else if (choice == 3)
			test_stack();
		else if (choice == 4)
			test_queue();
		else if (choice == 5)
			test_map();
		else if (choice != 6)
			std::cout << "Choice invalid\n";
	}
	return (0);
}
