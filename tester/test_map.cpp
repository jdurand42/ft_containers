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

template<typename vector, typename my_vector>
static bool check_if_equals2(vector v, my_vector mv)
{
	std::map<std::string, std::string>::iterator vi = v.begin();
	std::map<std::string, std::string>::iterator ve = v.end();
	ft::Map<std::string, std::string>::iterator mvi = mv.begin();
	ft::Map<std::string, std::string>::iterator mve = mv.end();
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

template<typename it1, typename it2>
static bool check_range(it1 first1, it1 end1, it2 first2, it2 end2)
{
	for (; first1 != end1 && first2 != end2; first1++, first2++)
	{
		if ((*first1).first != (*first2).first || (*first1).second != (*first2).second)
			return (false);
	}
	return (true);
}

template<typename it>
static bool check_it(it i, it i2)
{
	if (i == i2)
		return (true);
	return (false);
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

static void operations()
{
	std::cout << BOLDMAGENTA << "------OPERATIONS----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	m["lollol"] = "420";
	m["tamere"] = "lol";
	m["richard"] = "henri";
	m["henri"] = "richard";
	ft::Map<std::string, std::string> mm(m.begin(), m.end());

	ft_print("find(key) ", m.find("xavier")->second, mm.find("xavier")->second);
	ft_print("find(key) ", m.find("niel")->second, mm.find("niel")->second);
	ft_print("find(key) ", m.find("lol")->second, mm.find("lol")->second);
	//std::cout << m.find("niel1")->second;
	//ft_print("find(key non existing) ", m.find("niel1"), mm.find("niel1")->second);
	//ft_print("find(key) ", *(m.find("niel")), *(mm.find("niel")));
	//ft_print("find(key) ", *(m.find("lol")), *(mm.find("lol"))); // problem
	ft_print("find(key non existing) ", check_it(mm.end(), mm.find("niel1")), true);
	m.find("xavier")->second = "424242";
	mm.find("xavier")->second = "424242";
	ft_print("find(key after modification) ", m.find("xavier")->second, mm.find("xavier")->second);

	ft_print("count(key) ", m.count("lol"), mm.count("lol"));
	ft_print("count(key) ", m.count(""), mm.count(""));
	ft_print("count(key) ", m.count("   "), mm.count("   "));

	ft_print("lower_bound(key) ", *(m.lower_bound("lol")) == *(mm.lower_bound("lol")), true);
	ft_print("lower_bound(key) ", *(m.lower_bound("niel")) == *(mm.lower_bound("niel")), true);
	ft_print("lower_bound(key non existing) ", *(m.lower_bound("niel1")) == *(mm.lower_bound("niel1")), true);

	ft_print("upper_bound(key) ", *(m.upper_bound("lol")) == *(mm.upper_bound("lol")), true);
	ft_print("upper_bound(key) ", *(m.upper_bound("henri")) == *(mm.upper_bound("henri")), true);
	ft_print("upper_bound(key non existing) ", *(m.upper_bound("niel1")) == *(mm.upper_bound("niel1")), true);

	ft_print("equal_range(key) ", check_range(m.equal_range("lol").first, m.equal_range("lol").second, mm.equal_range("lol").first, mm.equal_range("lol").second), true);
	ft_print("equal_range(key) ", check_range(m.equal_range("henri").first, m.equal_range("henri").second, mm.equal_range("henri").first, mm.equal_range("henri").second), true);
	ft_print("equal_range(key non existing) ", check_range(m.equal_range("jean-michel").first, m.equal_range("jean-michel").second, mm.equal_range("jean-michel").first, mm.equal_range("jean-michel").second), true);
}

static void obeservers()
{
	std::map<std::string, std::string> m;
	ft::Map<std::string, std::string> map;
	// plus tard
}

static void modifiers()
{
	std::cout << BOLDMAGENTA << "------- MODIFIERS----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	m["lollol"] = "420";
	m["tamere"] = "lol";
	m["richard"] = "henri";
	m["henri"] = "richard";
	ft::Map<std::string, std::string> mm(m.begin(), m.end());

	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).second == true, mm.insert(std::make_pair("cobaye", "michel")).second == true);
	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).first->second, mm.insert(std::make_pair("cobaye", "michel")).first->second);
	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).second == false, mm.insert(std::make_pair("cobaye", "michel")).second == false);

	ft_print("Insert(pos, value): ", m.insert(m.begin(), std::make_pair("1", "1"))->second, mm.insert(mm.begin(), std::make_pair("1", "1"))->second);
	ft_print("Insert(pos, value): ", m.insert(m.begin(), std::make_pair("lol", "1"))->second, mm.insert(mm.begin(), std::make_pair("lol", "1"))->second);

	std::pair<const std::string, std::string> p1 = std::make_pair("bonjour", "aurevoir");
	std::pair<const std::string, std::string> p2 = std::make_pair("niel", "free2");
	std::pair<const std::string, std::string> p3 = std::make_pair("miel", "bon");
	std::pair<const std::string, std::string> p4 = std::make_pair("hey", "marcarena");
	std::vector<std::pair<const std::string, std::string> > v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	m.insert(v.begin(), v.end());
	mm.insert(v.begin(), v.end());

	ft_print("Insert (first, last): ", m["hey"], mm["hey"]);
	ft_print("Insert (first, last): ", m["miel"], mm["miel"]);
	ft_print("Insert (first, last): ", m["bonjour"], mm["bonjour"]);
	ft_print("Insert (first, last): ", m["niel"], mm["niel"]);

	ft_print("Erase (key): ", m.erase("miel"), mm.erase("miel"));
	ft_print("Erase (key non existing): ", m.erase("prout"), mm.erase("prout"));
	m.erase(m.find("henri"));
	mm.erase(mm.find("henri"));

	ft_print("Erase (pos): ", check_if_equals2(m, mm), true);
	ft_print("Erase (pos): ", m.size(), mm.size());
	m.erase(m.find("hey"));
	mm.erase(mm.find("hey"));
	ft_print("Erase (pos): ", check_if_equals2(m, mm), true);


}

void test_map()
{
	std::cout << BOLDYELLOW << "\n------TEST MAP----------\n\n" << RESET;
	constructors();
	elements_access();
	capacity();
	operations();
	modifiers();
}
