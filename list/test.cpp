#include <iostream>

int main()
{
	int p = 12;
	int *s = NULL;

	int *b = s;
	s = &p;

	std::cout << *b << std::endl;
}
