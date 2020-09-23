#include "../list/List.hpp"
#include "../vector/Vector.hpp"
#include "../map/Map.hpp"
#include "../stack/Stack.hpp"
#include "../queue/Queue.hpp"

#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <unistd.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"

#define TIME 10000

class Generic
{
	public:
	Generic()
	{
		std::cout << "Generic constructor called\n";
		_a = 1;
		_b = 2;
	};

	~Generic()
	{
		std::cout << "Generic destructor called\n";
	};

	void print()
	{
		std::cout << "Generic method called: " << _a << " " << _b << std::endl;
	};

	int _a;
	int _b;
};

template<typename T>
void ft_print(std::string method, T container, T my_container)
{
	usleep(TIME);
	std::cout << "---- Test on " << method << std::endl;
	if (container == my_container)
		std::cout << GREEN << "OK -> ";
	else
		std::cout << RED << "ERROR -> ";
	std::cout << "Expected: " << container << " | " << "Got: " << my_container;
	std::cout << RESET << std::endl;
};

void test_vector();
void test_list();
void test_map();
void test_queue();
void test_stack();
