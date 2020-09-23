#include "tester.hpp"


template<typename vector, typename my_vector>
static bool check_if_equals_str(vector v, my_vector mv)
{
	std::list<std::string>::iterator vi = v.begin();
	std::list<std::string>::iterator ve = v.end();
	ft::List<std::string>::iterator mvi = mv.begin();
	ft::List<std::string>::iterator mve = mv.end();
	if (v.size() != mv.size())
		return false;
	for (; vi != ve && mvi != mve; vi++, mvi++)
	{
		if (*mvi != *vi)
			return (false);
	}
	return (true);
}

template<typename vector, typename my_vector>
static bool check_if_equals(vector v, my_vector mv)
{
	std::list<int>::iterator vi = v.begin();
	std::list<int>::iterator ve = v.end();
	ft::List<int>::iterator mvi = mv.begin();
	ft::List<int>::iterator mve = mv.end();
	if (v.size() != mv.size())
		return false;
	for (; vi != ve && mvi != mve; vi++, mvi++)
	{
		//std::cout << *vi << ": " << *mvi << std::endl;
		if (*mvi != *vi)
			return (false);
	}
	return (true);
}

static void constructors()
{
	std::cout << BOLDYELLOW << " ---- Construtors ----\n" << RESET;
	std::list<std::string> l;
	ft::List<std::string> ml;
	ft_print("List(): ", l.size(), ml.size());

	std::list<std::string> l1(10, "42");
	ft::List<std::string> ml1(10, "42");
	ft_print("List(count, value): ", l1.size(), ml1.size());
	ft_print("List(count, value): ", check_if_equals_str(l1, ml1), true);

	std::list<std::string> l2(5);
	ft::List<std::string> ml2(5);
	ft_print("List(count): ", check_if_equals_str(l2, ml2), true);

	std::list<std::string> l3(l1.begin(), l1.end());
	ft::List<std::string> ml3(l1.begin(), l1.end());
	ft_print("List(it, it): ", check_if_equals_str(l3, ml3), true);

	std::list<std::string> l4(l1);
	ft::List<std::string> ml4(ml1);
	ft_print("List(list): ", check_if_equals_str(l4, ml4), true);

	l4 = l2;
	ml4 = ml2;
	ft_print("List = list: ", check_if_equals_str(l4, ml4), true);
}

static void capacity()
{
	std::cout << BOLDYELLOW << " ---- Capacity ----\n" << RESET;
	std::list<int> l;
	ft::List<int> ml;

	ft_print(" Empty : ", l.empty(), ml.empty());
	l.push_back(12);
	ml.push_back(12);
	ft_print(" Empty : ", l.empty(), ml.empty());
	ft_print(" size : ", l.size(), ml.size());
	ft_print("Max size: ", l.max_size(), ml.max_size());
}

static void elements_access()
{
	std::cout << BOLDYELLOW << " ---- elements_access ----\n" << RESET;

	std::list<int> lt;
	for (int i = 0; i < 10; i++)
		lt.push_back(i);

	ft::List<int> ml(lt.begin(), lt.end());
	ft_print("front: ", lt.front(), ml.front());
	ft_print("back: ", lt.back(), ml.back());
	lt.push_front(125);
	ml.push_front(125);
	ft_print("back: ", lt.back(), ml.back());
	ft_print("front: ", lt.front(), ml.front());

	std::list<std::string> l1(1, "XAVIER NIEL");
	ft::List<std::string> ml1(1, "XAVIER NIEL");
	ft_print("back: ", l1.back(), ml1.back());
	ft_print("front: ", l1.front(), ml1.front());
}

static void iterators()
{
	std::cout << BOLDYELLOW << " ---- iterators ----\n" << RESET;
	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	ft::List<int> ml(l.begin(), l.end());

	std::list<int>::iterator vit = l.begin();
	std::list<int>::iterator vet = l.end();
	ft::List<int>::iterator mvit = ml.begin();
	ft::List<int>::iterator mvet = ml.end();

	ft_print("Begin: ", *vit, *mvit);
	ft_print("--end", *(--vet), *(--mvet));
	ft_print("Post incrementqtion", *(vit++), *(mvit++));
	ft_print("Post incrementqtion", *vit, *mvit);
	ft_print("Pre-incrementation", *(++vit), *(++mvit));
	ft_print("Pre-decrementation", *(--vit), *(--mvit));
	ft_print("Post-decrementation", *(vit--), *(mvit--));
	ft_print("Post decrementqtion", *vit, *mvit);
	ft_print(" it == it: ", vit == l.begin(), mvit == ml.begin());
	ft_print(" it != it: ", vit != l.begin(), mvit != ml.begin());

}

static void reverse_iterator()
{
	std::cout << BOLDYELLOW << " ---- reverse_iterators ----\n" << RESET;
	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	ft::List<int> ml(l.begin(), l.end());

	std::list<int>::reverse_iterator vit = l.rbegin();
	std::list<int>::reverse_iterator vet = l.rend();
	ft::List<int>::reverse_iterator mvit = ml.rbegin();
	ft::List<int>::reverse_iterator mvet = ml.rend();

	ft_print("Begin: ", *vit, *mvit);
	ft_print("Post incrementqtion", *(vit++), *(mvit++));
	ft_print("Post incrementqtion", *vit, *mvit);
	ft_print("Pre-incrementation", *(++vit), *(++mvit));
	ft_print("Pre-decrementation", *(--vit), *(--mvit));
	ft_print("Post-decrementation", *(vit--), *(mvit--));
	ft_print("Post decrementqtion", *vit, *mvit);
	ft_print(" it == it: ", vit == l.rbegin(), mvit == ml.rbegin());
	ft_print(" it != it: ", vit != l.rbegin(), mvit != ml.rbegin());

}

static void modifiers()
{
	std::cout << BOLDYELLOW << " ---- MODIFIERS ----\n" << RESET;
	std::list<int> l;
	//for (int i = 0; i < 10; i++)
	//	l.push_back(i);
	ft::List<int> ml;

	l.assign(50, 42);
	ml.assign((ft::List<int>::size_type)50, (ft::List<int>::value_type)42);
	ft_print("assign (count, value): ", check_if_equals(l, ml), true);
	std::list<int> l1(10, 35);
	l.assign(l1.begin(), l1.end());
	ml.assign(l1.begin(), l1.end());
	ft_print("assign (input_iterator, input_iterator): ", check_if_equals(l, ml), true);

	l.push_front(100);
	ml.push_front(100);
	ft_print("push_front: ", check_if_equals(l, ml), true);
	l.pop_front();
	ml.pop_front();
	ft_print("pop_front: ", check_if_equals(l, ml), true);

	l.push_back(1);
	ml.push_back(1);
	ft_print("push_back: ", check_if_equals(l, ml), true);
	l.pop_back();
	ml.pop_back();
	ft_print("pop_back: ", check_if_equals(l, ml), true);

	l.push_front(100);
	ml.push_front(100);

	l.insert(l.begin(), 58);
	ml.insert(ml.begin(), 58);
	ft_print("insert(pos, value): ", check_if_equals(l, ml), true);
	l.insert(++l.begin(), 10);
	ml.insert(++ml.begin(), (ft::List<int>::value_type)10);
	ft_print("insert(pos, value): ", check_if_equals(l, ml), true);
	l.insert(--l.end(), 10);
	ml.insert(--ml.end(), (ft::List<int>::value_type)10);
	ft_print("insert(pos, value): ", check_if_equals(l, ml), true);
	l.insert(l.end(), 10);
	ml.insert(ml.end(), (ft::List<int>::value_type)10);
	ft_print("insert(pos, value): ", check_if_equals(l, ml), true);

	l.insert(l.begin(), 15, 58);
	ml.insert(ml.begin(), (ft::List<int>::size_type)15, (ft::List<int>::value_type)58);
	ft_print("insert(pos, n, value): ", check_if_equals(l, ml), true);
	l.insert(++l.begin(), 3, 10);
	ml.insert(++ml.begin(), (ft::List<int>::size_type)3, (ft::List<int>::value_type)10);
	ft_print("insert(pos, n, value): ", check_if_equals(l, ml), true);
	l.insert(--l.end(), 5, 10);
	ml.insert(--ml.end(), (ft::List<int>::size_type)5, (ft::List<int>::value_type)10);
	ft_print("insert(pos, n, value): ", check_if_equals(l, ml), true);
	l.insert(l.end(), 2, 10);
	ml.insert(ml.end(), (ft::List<int>::size_type)2, (ft::List<int>::value_type)10);
	ft_print("insert(pos, n, value): ", check_if_equals(l, ml), true);

	std::list<int> l3(10, 25);
	l3.push_back(12);
	l3.push_front(389);
	l.insert(l.begin(), l3.begin(), l3.end());
	ml.insert(ml.begin(), l3.begin(), l3.end());
	ft_print("insert(pos, it, end): ", check_if_equals(l, ml), true);
	l.insert(++l.begin(), l3.begin(), l3.end());
	ml.insert(++ml.begin(), l3.begin(), l3.end());
	ft_print("insert(pos, it, end): ", check_if_equals(l, ml), true);
	l.insert(--l.end(), l3.begin(), l3.end());
	ml.insert(--ml.end(), l3.begin(), l3.end());
	ft_print("insert(pos, it, end): ", check_if_equals(l, ml), true);
	l.insert(l.end(), l3.begin(), l3.end());
	ml.insert(ml.end(), l3.begin(), l3.end());
	ft_print("insert(pos, it, end): ", check_if_equals(l, ml), true);

	l.erase(l.begin());
	ml.erase(ml.begin());
	ft_print("erase(pos): ", check_if_equals(l, ml), true);
	l.erase(--l.end());
	ml.erase(--ml.end());
	ft_print("erase(pos): ", check_if_equals(l, ml), true);
	l.erase(++l.begin());
	ml.erase(++ml.begin());
	ft_print("erase(pos): ", check_if_equals(l, ml), true);
	l.erase(++l.begin(), --l.end());
	ml.erase(++ml.begin(),--ml.end());
	ft_print("erase(it, end): ", check_if_equals(l, ml), true);
	l.erase(l.begin(), l.end());
	ml.erase(ml.begin(), ml.end());
	ft_print("erase(it, end): ", check_if_equals(l, ml), true);




}

void test_list()
{
	std::cout << BOLDMAGENTA << "\n------ TEST ON LIST -------\n\n" << RESET;
	constructors();
	capacity();
	elements_access();
	iterators();
	reverse_iterator();
	modifiers();
}
