#include <iostream>
#include <string>

template<typename iterator>
struct Reverse_Iterator: public iterator
{
	typedef Reverse_Iterator<iterator> reverse_iterator;
	typedef typename 	iterator::difference_type difference_type;
	typedef typename 	iterator::size_type		size_type;
	typedef typename	iterator::pointer pointer;
	typedef typename	iterator::reference reference;
	typedef typename	iterator::value_type value_type;
	typedef typename	iterator::const_reference const_reference;
	typedef typename	iterator::const_pointer const_pointer;

	Reverse_Iterator()
	{
	};

	Reverse_Iterator(const Reverse_Iterator& it)
	{
		_base = it._base;
	};

	void operator = (const Reverse_Iterator& it)
	{
		_base = it._base;
	};

	Reverse_Iterator(iterator base): _base(base)
	{}

	~Reverse_Iterator() {};

	bool operator == (const Reverse_Iterator& it) const
	{
		return (it._base == _base);
	};

	bool operator != (const Reverse_Iterator& it) const
	{
		return (it._base != _base);
	};

	reference operator * ()
	{
		return (*_base);
	};

	pointer operator -> ()
	{
		return (&(*_base));
	};

	Reverse_Iterator& operator ++ ()
	{
		_base--;
		return (*this);
	};

	Reverse_Iterator& operator -- ()
	{
		_base++;
		return (*this);
	};

	Reverse_Iterator operator ++ (int)
	{
		Reverse_Iterator b = *this;

		_base--;
		return (b);
	};

	Reverse_Iterator operator -- (int)
	{
	 	Reverse_Iterator b = *this;

		_base++;
		return (b);
	};

	Reverse_Iterator operator + (difference_type n)
	{
		Reverse_Iterator b;

		b._base = _base + n;
		return (b);
	};

	Reverse_Iterator operator - (difference_type n)
	{
		Reverse_Iterator b;

		b._base = _base - n;
		return (b);
	};

	difference_type operator - (Reverse_Iterator it)
	{
		return (_base - it._base);
	};

	void operator += (difference_type n)
	{
		_base += n;
	};

	void operator -= (difference_type n)
	{
		_base += n;
	};

	Reverse_Iterator operator [] (difference_type n)
	{
		Reverse_Iterator b;

		b._base = _base + n;
		return (b);
	};

	bool operator < (const Reverse_Iterator& it) const
	{
		return (_base < it._base);
	};

	bool operator <= (const Reverse_Iterator& it) const
	{
		return (_base <= it._base);
	};

	bool operator > (const Reverse_Iterator& it) const
	{
		return (_base > it._base);
	};

	bool operator >= (const Reverse_Iterator& it) const
	{
		return (_base >= it._base);
	};

	private:
	iterator _base;
};
