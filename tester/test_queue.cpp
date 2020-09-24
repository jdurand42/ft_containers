#include "tester.hpp"

static void constructors()
{
	std::queue<int> s;
	ft::Queue<int> ms;
	ft_print("queue() ", s.size(), ms.size());
	std::queue<std::string> s1;
	ft::Queue<std::string> ms1;
	ft_print("queue() ", s1.size(), ms1.size());
	ft::Queue<char, ft::List<char> > ms2;
	ft_print("queue() ", s.size(), ms2.size());

	ft_print("empty() ", s.empty(), ms.empty());
	s.push(1);
	ms.push(1);
	ft_print("empty() ", s.empty(), ms.empty());
	ft_print("size() ", s.size(), ms.size());
	ft_print("push and front() ", s.front(), ms.front());
	s.push(2);
	ms.push(2);
	ft_print("push and back() ", s.back(), ms.back());
	ft_print("push and front() ", s.front(), ms.front());
	s.push(3);
	ms.push(3);
	ft_print("push and back() ", s.back(), ms.back());
	ft_print("size() ", s.size(), ms.size());
	ft_print("push and front() ", s.front(), ms.front());
	ft_print("push and back() ", s.size(), ms.size());
	s.pop();
	ms.pop();
	ft_print("size() ", s.size(), ms.size());
	ft_print("pop and back() ", s.back(), ms.back());
	s.pop();
	ms.pop();
	ft_print("size() ", s.size(), ms.size());
	ft_print("pop and back() ", s.back(), ms.back());

}

void test_queue()
{
	std::cout << "\n------TEST QUEUE----------\n\n";
	constructors();
}
