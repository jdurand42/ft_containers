#include "Stack.hpp"

int main()
{
	ft::Stack<int> stack;
	stack.push(10);
	stack.push(11);
	stack.push(12);
	stack.push(13);
	std::cout << stack.size() << " " << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.size() << " " << stack.top() << std::endl;
}
