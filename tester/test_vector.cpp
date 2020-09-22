#include "tester.hpp"

static void constructor_tests()
{
	std::cout << "TESTS ON CONSTRUCTORS\n";
	std::vector<int> i_v;
	ft::Vector<int> i_mv;
	//std::vector<std::string> s_v;
	//ft::Vector<std::string> s_mv;
//	std::vector<Generic> o_v;
//	ft::Vector<Generic> o_mv;
	std::cout << "Default constructor and template success\n";

	std::vector<int> i_v1(8);
	ft::Vector<int> i_mv1(8);
	ft_print("Vector(int count): ", i_v1.size(), i_mv1.size());
	ft_print("Values: ", i_v1[2], i_mv1[2]);
	std::cout << std::endl;

	std::vector<std::string> s_v1(12, "LOL CA MARCHE");
	ft::Vector<std::string> s_mv1(12, "LOL CA MARCHE");
	ft_print("Vector(int count, value value): ", s_v1.size(), s_mv1.size());
	ft_print("Values: ", s_v1[10], s_mv1[10]);
	std::cout << std::endl;

	std::vector<std::string> s_v2(3, "INPUTITERATOR");
	ft::Vector<std::string> s_mv2(s_v2.begin(), s_v2.end());
	ft_print("Vector(it first, it last): ", s_v2.size(), s_mv2.size());
	ft_print("Values: ", s_v2[2], s_mv2[2]);
	std::cout << std::endl;

	ft::Vector<std::string> s_mv3(12, "COPYCONSTRUCTOR");
	ft::Vector<std::string> s_mv4(s_mv3);
	ft_print("Vector(const Vector vec): ", s_mv3.size(), s_mv4.size());
	ft_print("Values: ", s_mv3[10], s_mv4[10]);
	std::cout << std::endl;

	s_mv4 = s_mv1;
	ft_print("Vector = Vector: ", s_mv4.size(), s_mv1.size());
	ft_print("Values: ", s_mv4[10], s_mv1[10]);
	std::cout << std::endl;
}

static void capacity_tests()
{
	std::cout << "\nTEST ON CAPACITY\n";

	std::vector<std::string> v;
	ft::Vector<std::string> mv;
	ft_print("Empty: ", v.empty(), mv.empty());
	v.push_back("not empty");
	mv.push_back("not empty");
	ft_print("Empty: ", v.empty(), mv.empty());
	std::cout << std::endl;


	ft_print("Size: ", v.size(), mv.size());
	std::cout << std::endl;

	std::vector<int> v1;
	ft::Vector<int> mv1;
	ft_print("Max Size: ", v1.max_size(), mv1.max_size());
	std::cout << std::endl;

	ft_print("capacity: ", v.capacity(), mv.capacity());
	std::cout << std::endl;

	v.resize(25);
	mv.resize(25);
	ft_print("Resize: ", v.size(), mv.size());
	ft_print("Value: ", v[24], mv[24]);
	v.resize(100, "lol");
	mv.resize(100, "lol");
	ft_print("Value: ", v[70], mv[70]);
	v.resize(10, "lol");
	mv.resize(10, "lol");
	ft_print("Value : ", v[9], mv[9]);
	ft_print("Test if not deallocated: ", v[18], mv[18]);
	ft_print("new size: ", v.size(), mv.size()); //for a seg faut :)
	std::cout << std::endl;

	v1.reserve(150);
	mv1.reserve(150);
	ft_print("Reserve(150) size: ", v1.size(), mv1.size());
	ft_print("Reserve(150) capacity: ", v1.capacity(), mv1.capacity());
	v1.reserve(15);
	mv1.reserve(15);
	ft_print("Reserve(15) size: ", v1.capacity(), mv1.capacity());
	std::cout << std::endl;
}

static void elements_access()
{
	std::cout << "\n----- test on elements_access\n";
	std::vector<int> v(10);
	ft::Vector<int> mv(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
		mv[i] = i;
	}
	ft_print("Operator []", v[2], mv[2]);
	ft_print("Operator []", v[3], mv[3]);
	ft_print("at ", v[2], mv[2]);
	ft_print("at ", v[3], mv[3]);
	ft_print("back ", v.back(), mv.back());
	ft_print("front ", v.front(), mv.front());
	std::cout << std::endl;

}

void test_vector()
{
	std::cout << "\n----------TEST VECTOR---------\n\n";

	constructor_tests();
	capacity_tests();
	elements_access();
}
