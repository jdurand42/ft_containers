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
	std::cout << BOLDYELLOW << "------CONSTRUCTORS----------\n" << RESET;
	std::map<std::string, int> m;
	ft::Map<std::string, int> mm;
	ft_print("map() ", check_if_equals(m, mm), true);
	m["xavier"] = 42;
	m["niel"] = 420;
	m["lol"] = 101;
	ft::Map<std::string, int> mm4;
	mm4["xavier"] = 42;
	mm4["niel"] = 420;
	mm4["lol"] = 101;
	ft::Map<std::string, int>::iterator i = mm4.begin();
	ft::Map<std::string, int>::iterator e = mm4.end();
	for (; i != e; i++)
		;
	ft_print("Test on small Iterations: ", true, true);
	ft::Map<std::string, int> mm1(mm4.begin(), mm4.end());
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
	std::cout << BOLDYELLOW << "------elements_access----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	ft::Map<std::string, std::string> mm;
	mm["xavier"] = "niel";
	mm["niel"] = "free";
	mm["lol"] = "42";

	ft_print("operator []: ", m["xavier"], mm["xavier"]);
	ft_print("operator []: ", m["lol"], mm["lol"]);
	ft_print("operator []: ", m["niel"], mm["niel"]);
	m["niel"] = "42";
	mm["niel"] = "42";
	ft_print("operator []: ", m["niel"], mm["niel"]);
}

static void capacity()
{
	std::cout << BOLDYELLOW << "------capacity----------\n" << RESET;
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
	std::cout << BOLDYELLOW << "------OPERATIONS----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	m["lollol"] = "420";
	m["tamere"] = "lol";
	m["richard"] = "henri";
	m["henri"] = "richard";
	m["xavier1"] = "niel";
	m["niel2"] = "free";
	m["lol3"] = "42";
	m["lollol4"] = "420";
	m["tamere5"] = "lol";
	m["richard6"] = "henri";
	m["henri7"] = "richard";
	ft::Map<std::string, std::string> mm;
	mm["xavier"] = "niel";
	mm["niel"] = "free";
	mm["lol"] = "42";
	mm["lollol"] = "420";
	mm["tamere"] = "lol";
	mm["richard"] = "henri";
	mm["henri"] = "richard";
	mm["xavier1"] = "niel";
	mm["niel2"] = "free";
	mm["lol3"] = "42";
	mm["lollol4"] = "420";
	mm["tamere5"] = "lol";
	mm["richard6"] = "henri";
	mm["henri7"] = "richard";

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

	ft_print("lower_bound(key) ", m.lower_bound("lol")->first == mm.lower_bound("lol")->first, true);
	ft_print("lower_bound(key) ", m.lower_bound("niel")->first == mm.lower_bound("niel")->first, true);
	ft_print("lower_bound(key non existing) ", m.lower_bound("niel1")->second == mm.lower_bound("niel1")->second, true);

	ft_print("upper_bound(key) ", m.upper_bound("lol")->first == mm.upper_bound("lol")->first, true);
	ft_print("upper_bound(key) ", m.upper_bound("henri")->first == mm.upper_bound("henri")->first, true);
	ft_print("upper_bound(key non existing) ", m.upper_bound("niel1")->second == mm.upper_bound("niel1")->second, true);

	ft_print("equal_range(key) ", check_range(m.equal_range("lol").first, m.equal_range("lol").second, mm.equal_range("lol").first, mm.equal_range("lol").second), true);
	ft_print("equal_range(key) ", check_range(m.equal_range("henri").first, m.equal_range("henri").second, mm.equal_range("henri").first, mm.equal_range("henri").second), true);
	ft_print("equal_range(key non existing) ", check_range(m.equal_range("jean-michel").first, m.equal_range("jean-michel").second, mm.equal_range("jean-michel").first, mm.equal_range("jean-michel").second), true);

	ft_print("lower_bound(key) ", m.lower_bound("lol")->first == mm.lower_bound("lol")->first, true);
	ft_print("lower_bound(key) ", m.lower_bound("niel")->first == mm.lower_bound("niel")->first, true);
	ft_print("lower_bound(key non existing) ", m.lower_bound("niel1")->second == mm.lower_bound("niel1")->second, true);

	ft_print("upper_bound(key) ", m.upper_bound("tamere")->first == mm.upper_bound("tamere")->first, true);
	ft_print("upper_bound(key) ", m.upper_bound("lol3")->first == mm.upper_bound("lol3")->first, true);
	ft_print("upper_bound(key non existing) ", m.upper_bound("niel1")->second == mm.upper_bound("niel1")->second, true);
}

static void modifiers()
{
	std::cout << BOLDYELLOW << "------- MODIFIERS----------\n" << RESET;
	std::map<std::string, std::string> m;
	m["xavier"] = "niel";
	m["niel"] = "free";
	m["lol"] = "42";
	m["lollol"] = "420";
	m["tamere"] = "lol";
	m["richard"] = "henri";
	m["henri"] = "richard";
	ft::Map<std::string, std::string> mm;
	mm["xavier"] = "niel";
	mm["niel"] = "free";
	mm["lol"] = "42";
	mm["lollol"] = "420";
	mm["tamere"] = "lol";
	mm["richard"] = "henri";
	mm["henri"] = "richard";


	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).second == true, mm.insert(ft::Pair<const std::string, std::string>("cobaye", "michel")).second == true);
	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).first->second, mm.insert(ft::Pair<const std::string, std::string>("cobaye", "michel")).first->second);
	ft_print("Insert (value): ", m.insert(std::make_pair("cobaye", "michel")).second == false, mm.insert(ft::Pair<const std::string, std::string>("cobaye", "michel")).second == false);

	ft_print("Insert(pos, value): ", m.insert(m.begin(), std::make_pair("1", "1"))->second, mm.insert(mm.begin(), ft::Pair<const std::string, std::string>("1", "1"))->second);
	ft_print("Insert(pos, value): ", m.insert(m.begin(), std::make_pair("lol", "1"))->second, mm.insert(mm.begin(), ft::Pair<const std::string, std::string>("lol", "1"))->second);

	std::pair<const std::string, std::string> p1 = std::make_pair("bonjour", "aurevoir");
	std::pair<const std::string, std::string> p2 = std::make_pair("niel", "free2");
	std::pair<const std::string, std::string> p3 = std::make_pair("miel", "bon");
	std::pair<const std::string, std::string> p4 = std::make_pair("hey", "macarena");
	std::vector<std::pair<const std::string, std::string> > v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	m.insert(v.begin(), v.end());
	ft::Map<std::string, std::string> mm2;
	mm2["bonjour"] = "aurevoir";
	mm2["niel"] = "free2";
	mm2["miel"] = "bon";
	mm2["hey"] = "macarena";
	mm.insert(mm2.begin(), mm2.end());


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

	m.erase(m.find("bonjour"), ++m.find("bonjour"));
	mm.erase(mm.find("bonjour"), ++mm.find("bonjour"));
	ft_print("Erase (first, last): ", m.size(), mm.size());
	std::map<std::string, std::string> m2;
	m2["xavier"] = "niel";
	m2["niel"] = "free";
	m2["lol"] = "42";
	ft::Map<std::string, std::string> mm3;
	mm3["xavier"] = "niel";
	mm3["niel"] = "free";
	mm3["lol"] = "42";
	m.swap(m2);
	mm.swap(mm3);
	ft_print("swap : ", m.size(), mm.size());
	ft_print("swap : ", m2.size(), mm3.size());

	m.clear();
	mm.clear();
	ft_print("clear(): ", m.size(), mm.size());
}

static void iterators()
{
	std::cout << BOLDYELLOW << " ---- iterators ----\n" << RESET;
	std::map<int, int> l;
	for (int i = 0; i < 10; i++)
		l[i] = i;
	ft::Map<int, int> ml;
	for (int i = 0; i < 10; i++)
		ml[i] = i;

	std::map<int, int>::iterator vit = l.begin();
	std::map<int, int>::iterator vet = l.end();
	ft::Map<int, int>::iterator mvit = ml.begin();
	ft::Map<int, int>::iterator mvet = ml.end();

	ft_print("Begin: ", vit->second, mvit->second);
	ft_print("--end", (--vet)->second, (--mvet)->second);
	ft_print("Post incrementqtion", (vit++)->second, (mvit++)->second);
	ft_print("Post incrementqtion", vit->second, mvit->second);
	ft_print("Pre-incrementation", (++vit)->second, (++mvit)->second);
	ft_print("Pre-decrementation", (--vit)->second, (--mvit)->second);
	ft_print("Post-decrementation", (vit--)->second, (mvit--)->second);
	ft_print("Post decrementqtion", vit->second, mvit->second);
	ft_print(" it == it: ", vit == l.begin(), mvit == ml.begin());
	ft_print(" it != it: ", vit != l.begin(), mvit != ml.begin());
}

static void reverse_iterators()
{
	std::cout << BOLDYELLOW << " ---- Reverse iterators ----\n" << RESET;
	std::map<int, int> l;
	for (int i = 0; i < 10; i++)
		l[i] = i;
	ft::Map<int, int> ml;
	for (int i = 0; i < 10; i++)
		ml[i] = i;

	std::map<int, int>::reverse_iterator vit = l.rbegin();
	std::map<int, int>::reverse_iterator vet = l.rend();
	ft::Map<int, int>::reverse_iterator mvit = ml.rbegin();
	ft::Map<int, int>::reverse_iterator mvet = ml.rend();

	ft_print("Begin: ", vit->second, mvit->second);
	ft_print("--end", (--vet)->second, (--mvet)->second);
	ft_print("Post incrementqtion", (vit++)->second, (mvit++)->second);
	ft_print("Post incrementqtion", vit->second, mvit->second);
	ft_print("Pre-incrementation", (++vit)->second, (++mvit)->second);
	ft_print("Pre-decrementation", (--vit)->second, (--mvit)->second);
	ft_print("Post-decrementation", (vit--)->second, (mvit--)->second);
	ft_print("Post decrementqtion", vit->second, mvit->second);
	ft_print(" it == it: ", vit == l.rbegin(), mvit == ml.rbegin());
	ft_print(" it != it: ", vit != l.rbegin(), mvit != ml.rbegin());
}

static void const_iterators()
{
	std::cout << BOLDYELLOW << " ---- const iterators ----\n" << RESET;
	std::map<int, int> l;
	for (int i = 0; i < 10; i++)
		l[i] = i;
	ft::Map<int, int> ml;
	for (int i = 0; i < 10; i++)
		ml[i] = i;

	std::map<int, int>::const_iterator vit = l.begin();
	std::map<int, int>::const_iterator vet = l.end();
	ft::Map<int, int>::const_iterator mvit = ml.begin();
	ft::Map<int, int>::const_iterator mvet = ml.end();
	//mvit->second = 12;
	ft_print("Begin: ", vit->second, mvit->second);
	ft_print("--end", (--vet)->second, (--mvet)->second);
	ft_print("Post incrementqtion", (vit++)->second, (mvit++)->second);
	ft_print("Post incrementqtion", vit->second, mvit->second);
	ft_print("Pre-incrementation", (++vit)->second, (++mvit)->second);
	ft_print("Pre-decrementation", (--vit)->second, (--mvit)->second);
	ft_print("Post-decrementation", (vit--)->second, (mvit--)->second);
	ft_print("Post decrementqtion", vit->second, mvit->second);
	ft_print(" it == it: ", vit == l.begin(), mvit == ml.begin());
	ft_print(" it != it: ", vit != l.begin(), mvit != ml.begin());
}

static void const_reverse_iterators()
{
	std::cout << BOLDYELLOW << " ---- Reverse iterators ----\n" << RESET;
	std::map<int, int> l;
	for (int i = 0; i < 10; i++)
		l[i] = i;
	ft::Map<int, int> ml;
	for (int i = 0; i < 10; i++)
		ml[i] = i;

	std::map<int, int>::const_reverse_iterator vit = l.rbegin();
	std::map<int, int>::const_reverse_iterator vet = l.rend();
	ft::Map<int, int>::const_reverse_iterator mvit = ml.rbegin();
	ft::Map<int, int>::const_reverse_iterator mvet = ml.rend();


//	mvit->second = 12;
	ft_print("Begin: ", vit->second, mvit->second);
	ft_print("--end", (--vet)->second, (--mvet)->second);
	ft_print("Post incrementqtion", (vit++)->second, (mvit++)->second);
	ft_print("Post incrementqtion", vit->second, mvit->second);
	ft_print("Pre-incrementation", (++vit)->second, (++mvit)->second);
	ft_print("Pre-decrementation", (--vit)->second, (--mvit)->second);
	ft_print("Post-decrementation", (vit--)->second, (mvit--)->second);
	ft_print("Post decrementqtion", vit->second, mvit->second);
	ft_print(" it == it: ", vit == l.rbegin(), mvit == ml.rbegin());
	ft_print(" it != it: ", vit != l.rbegin(), mvit != ml.rbegin());
}

void test_map()
{
	std::cout << BOLDMAGENTA << "\n------TEST MAP----------\n\n" << RESET;
	constructors();
	elements_access();
	capacity();
	operations();
	modifiers();
	iterators();
	reverse_iterators();
	const_iterators();
	const_reverse_iterators();
}
