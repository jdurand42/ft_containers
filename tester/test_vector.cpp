#include "tester.hpp"

template<typename vector, typename my_vector>
static bool check_if_equals(vector v, my_vector mv)
{
	if (v.size() != mv.size())
		return false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != mv[i])
			return (false);
	}
	return (true);
}

static void constructor_tests()
{
	std::cout << BOLDYELLOW << "---- TESTS ON CONSTRUCTORS ---- \n" << RESET;
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
	std::cout << BOLDYELLOW << "\n---- TEST ON CAPACITY ----\n" << RESET;

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

	//v.resize(28);
	mv.resize(28);
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
	std::cout << BOLDYELLOW << "\n----- test on elements_access -----\n" << RESET;
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

static void iterators()
{
	std::cout << BOLDYELLOW << "\n----- test on elements_access ----- \n" << RESET;
	std::vector<int> v(10);
	ft::Vector<int> mv(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
		mv[i] = i;
	}
	std::vector<int>::iterator vit = v.begin();
	ft::Vector<int>::iterator mvit = mv.begin();
	std::vector<int>::iterator vet = v.end();
	ft::Vector<int>::iterator mvet = mv.end();

	ft_print("Begin: ", *vit, *mvit);
	ft_print("End ( end - begin)", vet - vit, mvet - mvit);
	ft_print("Post incrementqtion", *(vit++), *(mvit++));
	ft_print("Post incrementqtion", *vit, *mvit);
	ft_print("Pre-incrementation", *(++vit), *(++mvit));
	ft_print("Pre-decrementation", *(--vit), *(--mvit));
	ft_print("Post-decrementation", *(vit--), *(mvit--));
	ft_print("Post decrementqtion", *vit, *mvit);
	vit += 2;
	mvit += 2;
	ft_print("it += int ", *vit , *mvit);
	vit -= 2;
	mvit -= 2;
	ft_print("it -= int ", *vit, *mvit);
	vit[3] = 123;
	mvit[3] = 123;
	ft_print("it + int", *(vit + 2), *(mvit + 2));
	ft_print("it - int", *(vit + 4 - 3 ), *(mvit + 4 - 3));
	ft_print("it[3] ", vit[3], mvit[3]);
	ft_print("operator <", vit < vet, mvit < mvet);
	ft_print("operator <=", vit <= vet, mvit <= mvet);
	ft_print("operator >=", vit >= vet, mvit >= mvet);
	ft_print("operator !=", vit != vet, mvit != mvet);
	ft_print("operator ==", vit == vet, mvit == mvet);

	std::cout << BOLDYELLOW << "\nTest on reverse_iterator\n" << RESET;

	std::vector<int>::reverse_iterator vr = v.rbegin();
	ft::Vector<int>::reverse_iterator mvr = mv.rbegin();
	std::vector<int>::reverse_iterator ver = v.rend();
	ft::Vector<int>::reverse_iterator mver = mv.rend();

	ft_print("Begin: ", *vr, *mvr);
	ft_print("End ( end - begin)", ver - vr, mver - mvr);
	ft_print("Post incrementqtion", *(vr++), *(mvr++));
	ft_print("Post incrementqtion", *vr, *mvr);
	ft_print("Pre-incrementation", *(++vr), *(++mvr));
	ft_print("Pre-decrementation", *(--vr), *(--mvr));
	ft_print("Post-decrementation", *(vr--), *(mvr--));
	ft_print("Post decrementqtion", *vr, *mvr);
	vr += 4;
	mvr += 4;
	ft_print("it += int ", *vr , *mvr);
	vit -= 1;
	mvit -= 1;
	ft_print("it -= int ", *vr , *mvr);
	vr[3] = 123;
	mvr[3] = 123;
	ft_print("it + int", *(vr + 2), *(mvr + 2));
	ft_print("it - int", *(vr + 4 - 3 ), *(mvr + 4 - 3));
	ft_print("it[3] ", vr[3], mvr[3]);
	ft_print("operator <", vr < ver, mvr < mver);
	ft_print("operator <=", vr <= ver, mvr <= mver);
	ft_print("operator >=", vr >= ver, mvr >= mver);
	ft_print("operator !=", vr != ver, mvr != mver);
	ft_print("operator ==", vr == ver, mvr == mver);

}

static void modifiers()
{
	std::cout << BOLDYELLOW << "\n------ MODIFIERS -------\n\n" << RESET;
	std::vector<int> v;
	ft::Vector<int> mv;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		mv.push_back(i);
	}
	ft_print("push_back: ", v[0], mv[0]);
	ft_print("push_back: ", v[v.size() - 1], mv[mv.size() - 1]);
	v.pop_back();
	mv.pop_back();
	ft_print("pop_back: ", v[v.size() - 1], mv[mv.size() - 1]);

	//insert
	std::vector<int>::iterator it = v.insert(v.end() - 4, (int)42);
	ft::Vector<int>::iterator mit = mv.insert(mv.end() - 4, (int)42);
	ft_print("insert (pos, value): ", v[v.size() - 5], mv[mv.size() - 5]);
	ft_print("insert return: ", *it == 42, *mit == 42);
	v.insert(v.end() - 2, (std::vector<int>::size_type)10, (std::vector<int>::value_type)21);
	mv.insert(mv.end() - 2, (ft::Vector<int>::size_type)10, (ft::Vector<int>::value_type)21);
	ft_print("insert (pos, n, value): ", check_if_equals(v, mv), true);
/*	ft_print("insert (pos, n, value): ", v[v.size() - 3], mv[mv.size() - 3]);
	ft_print("insert (pos, n, value): ", v[v.size() - 1], mv[mv.size() - 1]);*/
	std::vector<int> v2;
	for (int i = 0; i < 20; i++)
		v2.push_back(i);
	v.insert(v.end() - 2, v2.begin() + 10, v2.end());
	mv.insert(mv.end() - 2, v2.begin() + 10, v2.end());
	ft_print("insert(pos, first, last): ", check_if_equals(v, mv), true);
	v.erase(v.end() - 3);
	mv.erase(mv.end() - 3);
	ft_print("erase(pos) ", check_if_equals(v, mv), true);
	v.erase(v.end() - 10, v.end() - 5);
	mv.erase(mv.end() - 10, mv.end() - 5);
	ft_print("erase(start, last) ", check_if_equals(v, mv), true);

	std::vector<int> v3;
	for (int i = 0; i < 100; i++)
		v3.push_back(i);
	ft::Vector<int> mv2;
	for (int i = 0; i < 100; i++)
		mv2.push_back(i);
	v.swap(v3);
	mv.swap(mv2);
	ft_print("swap() ", check_if_equals(v3, mv2), true);
	ft_print("swap() ", check_if_equals(v, mv), true);


	v.assign((std::vector<int>::size_type)120, (std::vector<int>::value_type)41);
	mv.assign((ft::Vector<int>::size_type)120, (ft::Vector<int>::value_type)41);
	ft_print("assign(n, value) ", check_if_equals(v, mv), true);
	v.assign((std::vector<int>::size_type)12, (std::vector<int>::value_type)42);
	mv.assign((ft::Vector<int>::size_type)12, (ft::Vector<int>::value_type)42);
	ft_print("assign(n, value) ", check_if_equals(v, mv), true);
	v.assign(v3.begin(), v3.end());
	mv.assign(v3.begin(), v3.end());
	ft_print("assign(first, last) ", check_if_equals(v, mv), true);




	v.clear();
	mv.clear();
	ft_print("clear", v.size(), mv.size());

}

static void operators()
{
	std::cout << BOLDYELLOW << "\n------ RELATIONAL OPERATORS -------\n\n" << RESET;
	std::vector<int> v;
	ft::Vector<int> mv;
	std::vector<int> v2;
	ft::Vector<int> mv2;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		mv.push_back(i);
		v2.push_back(-i);
		mv2.push_back(-i);
	}

	ft_print("v == v", v == v2, mv == mv2);
	ft_print("v != v", v != v2, mv != mv2);
	ft_print("v < v", v < v2, mv < mv2);
	ft_print("v <= v", v <= v2, mv <= mv2);
	ft_print("v > v", v > v2, mv > mv2);
	ft_print("v >= v", v >= v2, mv >= mv2);

	v2.push_back(42);
	mv2.push_back(42);

	ft_print("v == v", v == v2, mv == mv2);
	ft_print("v != v", v != v2, mv != mv2);
	ft_print("v < v", v < v2, mv < mv2);
	ft_print("v <= v", v <= v2, mv <= mv2);
	ft_print("v > v", v > v2, mv > mv2);
	ft_print("v >= v", v >= v2, mv >= mv2);

	ft::swap(mv, mv2);
	swap(v, v2);
	ft_print("external swap: ", check_if_equals(v, mv), true);
	ft_print("external swap: ", check_if_equals(v2, mv2), true);
}

void test_vector()
{
	std::cout << BOLDMAGENTA << "\n----------TEST VECTOR---------\n\n" << RESET;

	constructor_tests();
	capacity_tests();
	elements_access();
	iterators();
	modifiers();
	operators();
	//while (1);
}
