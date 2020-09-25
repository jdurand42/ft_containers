#include "tester.hpp"

template<typename vector, typename my_vector>
static bool check_if_equals(vector v, my_vector mv)
{
	std::map<std::string, int>::iterator vi = v.begin();
	std::map<std::string, int>::iterator ve = v.end();
	ft::Map<std::string, int>::iterator mvi = mv.begin();
	ft::Map<std::string, int>::iterator mve = mv.end();
	if (v.size() != mv.size())
		return false;
	for (; vi != ve && mvi != mve; vi++, mvi++)
	{
	//	std::cout << *vi << ": " << *mvi << std::endl;
		if ((*mvi).first != (*vi).first || (*mvi).second != (*vi).second)
			return (false);
	}
	return (true);
}

static void constructors()
{
	std::cout << BOLDMAGENTA << "------CONSTRUCTORS----------\n" << RESET;
	std::map<std::string, int> m;
	ft::Map<std::string, int> mm;
	ft_print("map() ", check_if_equals(m, mm), true);
	m["xavier"] = 42;
	m["niel"] = 420;
	m["lol"] = 101;
	ft::Map<std::string, int> mm1(m.begin(), m.end());
	ft_print("map(it, it) ", check_if_equals(m, mm1), true);
	ft::Map<std::string, int> mm2(mm1);
	ft_print("map(map) ", check_if_equals(m, mm2), true);
	ft_print("map(map) ", check_if_equals(m, mm1), true);
	ft::Map<std::string, int> mm3(mm1);
	mm1["xavier"] = 155;
	m["xavier"] = 155;
	mm3 = mm1;
	ft_print("map = map ", check_if_equals(m, mm1), true);
	ft_print("map = map ", check_if_equals(m, mm3), true);
	ft_print("map = map ", check_if_equals(m, mm2), false);
}

static void elements_access()
{
	std::cout << BOLDMAGENTA << "------elements_access----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	ft::Map<std::string, std::string> mm(m.begin(), m.end());
	ft_print("operator []: ", m["xavier"], mm["xavier"]);
	ft_print("operator []: ", m["lol"], mm["lol"]);
	ft_print("operator []: ", m["niel"], mm["niel"]);
	m["niel"] = "42";
	mm["niel"] = "42";
	ft_print("operator []: ", m["niel"], mm["niel"]);
}

static void capacity()
{
	std::cout << BOLDMAGENTA << "------capacity----------\n" << RESET;
	std::map<std::string, std::string> m;
	ft::Map<std::string, std::string> mm;
	ft_print("empty(): ", m.empty(), mm.empty());
	ft_print("size(): ", m.size(), mm.size());
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	mm["xavier"] = "niel";
	mm["niel"] = "free";
	mm["lol"] = "42";
	ft_print("empty(): ", m.empty(), mm.empty());
	ft_print("size(): ", m.size(), mm.size());
	ft_print("max size(): ", m.max_size(), mm.max_size());
	std::map<char, int> m1;
	ft::Map<char, int> mm1;
	ft_print("max size(): ", m1.max_size(), mm1.max_size());
	mm["niel"] = "free";
	m["niel"] = "free";
	ft_print("size(): ", m.size(), mm.size());
}

static void find()
{
	
}

void test_map()
{
	std::cout << BOLDYELLOW << "\n------TEST MAP----------\n\n" << RESET;
	constructors();
	elements_access();
	capacity();
}
