#include "tester.hpp"


static void test_all()
{
	test_vector();
	test_list();
	test_queue();
	test_stack();
	test_map();
}

int main(int ac, char** av)
{
	std::cout << "Type ./EXEC container_name1 container_name2 -> For specific containers\n";
	std::cout << "Without arguments it will do all tests\n";

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "vector")
				test_vector();
			else if (std::string(av[i]) == "list")
				test_list();
			else if (std::string(av[i]) == "map")
				test_map();
			else if (std::string(av[i]) == "queue")
				test_queue();
			else if (std::string(av[i]) == "stack")
				test_stack();
		}
	}
	else
		test_all();
	return (0);
}
