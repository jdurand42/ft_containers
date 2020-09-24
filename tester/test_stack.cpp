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

static void operators()
{
/*	std::cout << BOLDYELLOW << "\n------ RELATIONAL OPERATORS -------\n\n" << RESET;
	std::stack<int> v;
	ft::Stack<int> mv;
	std::stack<int> v2;
	ft::Stack<int> mv2;
	for (int i = 0; i < 10; i++)
	{
		v.push(i);
		mv.push(i);
		v2.push(-i);
		mv2.push(-i);
	}

	ft_print("v == v", v == v2, mv == mv2);
	ft_print("v != v", v != v2, mv != mv2);
	ft_print("v < v", v < v2, mv < mv2);
	ft_print("v <= v", v <= v2, mv <= mv2);
	ft_print("v > v", v > v2, mv > mv2);
	ft_print("v >= v", v >= v2, mv >= mv2);

	v2.push(42);
	mv2.push(42);

	ft_print("v == v", v == v2, mv == mv2);
	ft_print("v != v", v != v2, mv != mv2);
	ft_print("v < v", v < v2, mv < mv2);
	ft_print("v <= v", v <= v2, mv <= mv2);
	ft_print("v > v", v > v2, mv > mv2);
	ft_print("v >= v", v >= v2, mv >= mv2);
	*/
}

void test_stack()
{
	std::cout << "\n------TEST STACK----------\n\n";

	constructors();
//	operators();
}
