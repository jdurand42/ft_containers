#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
	template<typename Key, typename T>
	class Pair
	{
		public:

			Key         first;
			T           second;

	        Pair() {}
	        Pair(Key key, T data) : first(key), second(data) {}
	        Pair &operator=(const Pair &x) {
	                first = x.first;
	                second = x.second;
	                return *this; }
	        ~Pair() {}

	};

	template<typename Key, typename T>
	Pair<Key, T> make_pair(Key key, T t)
	{
		Pair<Key, T> pair(key, t);
		return (pair);
	};

	template<typename T>
	struct Less
	{
		bool operator()(const T& x, const T& y) const
		{
			return (x < y);
		}
	};

	template<typename T>
	class Allocator
	{
		public :
		//    typedefs
		typedef T value_type;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

		public :
		//    convert an allocator<T> to allocator<U>
		template<typename U>
		struct rebind
		{
			typedef Allocator<U> other;
		};

		public :
		explicit Allocator() {}
		~Allocator() {}
		explicit Allocator(Allocator const&) {}
		template<typename U>
		explicit Allocator(Allocator<U> const&) {}

		//    address
		pointer address(reference r)
		{
			return &r;
		}
		const_pointer address(const_reference r)
		{
			return &r;
		}

		//    memory allocation
		pointer allocate(size_type cnt, typename std::allocator<void>::const_pointer = 0)
		{
			return reinterpret_cast<pointer>(::operator new(cnt * sizeof (T)));
		}
		void deallocate(pointer p, size_type)
		{
			::operator delete(p);
		}

		size_type max_size() const
		{
			return std::numeric_limits<size_type>::max() / sizeof(T);
		}

		void construct(pointer p, const T& t)
		{
			new(p) T(t);
		}
		void destroy(pointer p)
		{
			p->~T();
		}

		bool operator==(Allocator const&)
		{
			return true;
		}
		bool operator!=(Allocator const& a)
		{
			return !operator==(a);
		}
	};
};

#endif
