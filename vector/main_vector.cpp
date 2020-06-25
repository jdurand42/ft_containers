#include "Vector.hpp"

int main()
{
	ft::Vector<int> v1(10, 42);

	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << std::endl;

	for (int i = 0; i < v1.size(); i++)
		v1.at(i) = i;

	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << std::endl;

	std::cout << std::endl << std::endl;

	for (int i = 10; i < 25; i++)
		v1.push_back(i);

	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << std::endl;

	std::cout << v1.front() << " " << v1.back() << std::endl;

	ft::Vector<int> copy(v1);

	for (int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << std::endl;

	std::cout << "CAPACITY: " << copy.capacity() << std::endl;

	ft::Vector<int> assign(5, 48);

	assign = copy;

	for (int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << std::endl;

	assign.reserve(2);
	assign.reserve(35);

	for (int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << std::endl;
	std::cout << "CAPACITY: " << assign.capacity() << std::endl;
	for (int i = 0; i < 5; i++)
		assign.pop_back();

		for (int i = 0; i < assign.size(); i++)
			std::cout << assign[i] << std::endl;
		std::cout << "CAPACITY: " << assign.capacity() << std::endl;

	std::cout << "\n\n----- Enter Iterators ------\n\n";

	ft::Vector<int>::Iterator it = assign.begin();
	ft::Vector<int>::Iterator end = assign.end();

	/*while (it != end)
	{
		*it++ = 350;
	}*/

	it = assign.begin();

	while (it != end)
	{
		std::cout << *it << std::endl;
		it++;
	}

	it = assign.begin();

	it += 3;
	std::cout << *(it + 3) << std::endl;

	std::cout  << it - end << std::endl;

	std::cout << *it[-2] << std::endl;

	if (it + 3 > it)
		std::cout << "lol\n";

	std::cout << "Max Size: " << assign.max_size() << std::endl;

	assign.resize(10);
	it = assign.begin();
	end = assign.end();
	while (it != end)
		std::cout << *it++ << std::endl;
	std::cout << "Size: " << assign.size() << " | capacity: " << assign.capacity() << std::endl;

	assign.resize(30);
	it = assign.begin();
	end = assign.end();
	while (it != end)
		std::cout << *it++ << std::endl;
	std::cout << "Size: " << assign.size() << " | capacity: " << assign.capacity() << std::endl;

	ft::Vector<int>::Iterator it2 = assign.begin();


	assign.erase(it2 + 4);
	it = assign.begin();

	assign.resize(10);
		end = assign.end();

	std::cout << std::endl;
	while (it != end)
		std::cout << *it++ << std::endl;


	ft::Vector<int>::Iterator it3 =	it2 + 3;
	ft::Vector<int>::Iterator it4 = it2 + 7;
	std::cout << "la : " << it4 - it2 << std::endl;
	assign.erase(it3, it4);
	std::cout << "lol";
	it = assign.begin();
	end = assign.end();
	std::cout << "lol";
	std::cout << std::endl;
	while (it != end)
		std::cout << *it++ << std::endl;

std::cout << std::endl;
	assign.insert(assign.begin() + 2, 50, 42);
	it = assign.begin();
	end = assign.end();
	while (it != end)
		std::cout << *it++ << std::endl;

	ft::swap(v1, assign);
	std::cout << "\nafter swap\n\n";
	for (int i = 0; i < v1.size(); i++)
		std::cout << v1[i] << std::endl;

	for (int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << std::endl;

	if (assign == assign)
		std::cout << "oui\n";
	std::cout << (assign == assign) << std::endl;
	std::cout << (assign !=  v1) << std::endl;
	std::cout << (assign <= assign) << std::endl;
	std::cout << (assign < v1) << std::endl;
	std::cout << (assign > v1) << std::endl;

	ft::Vector<int>::iterator it50 = assign.begin();
	//std::cout << "ici " << it50._t << std::endl;

	std::cout << "\n\nTest reverse_iterator\n\n";
	for (ft::Vector<int>::reverse_iterator it2 = assign.rbegin(),
	end2 = assign.rend(); it2 != end2; it2++)
		std::cout << *it2 << std::endl;

	return (0);
}
