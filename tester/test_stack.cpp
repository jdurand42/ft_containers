#include "tester.hpp"

static void constructors()
{
	std::stack<int> s;
	ft::Stack<int> ms;
	ft_print("Stack() ", s.size(), ms.size());
	std::stack<std::string> s1;
	ft::Stack<std::string> ms1;
	ft_print("Stack() ", s1.size(), ms1.size());
	ft::Stack<char, ft::List<char> > ms2;
	ft_print("Stack() ", s.size(), ms2.size());

	ft_print("empty() ", s.empty(), ms.empty());
	s.push(1);
	ms.push(1);
	ft_print("empty() ", s.empty(), ms.empty());
	ft_print("size() ", s.size(), ms.size());
	ft_print("push and top() ", s.top(), ms.top());
	s.push(2);
	ms.push(2);
	ft_print("push and top() ", s.top(), ms.top());
	s.push(3);
	ms.push(3);
	ft_print("push and top() ", s.top(), ms.top());
	ft_print("size() ", s.size(), ms.size());
	ft_print("push and top() ", s.size(), ms.size());
	s.pop();
	ms.pop();
	ft_print("size() ", s.size(), ms.size());
	ft_print("pop and top() ", s.top(), ms.top());
	s.pop();
	ms.pop();
	ft_print("size() ", s.size(), ms.size());
	ft_print("pop and top() ", s.top(), ms.top());

}

void test_stack()
{
	std::cout << "\n------TEST STACK----------\n\n";

	constructors();
}
