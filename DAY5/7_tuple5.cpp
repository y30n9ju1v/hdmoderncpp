
#include <iostream>

// Step4. move 지원

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
//	tuple(const T& n, const Types& ... args)
//		: value(n), base(args...) {}

	// forwarding reference 로 move 지원 생성자 만들기.
	template<typename U, typename ... Ts>
	tuple(U&& n, Ts&& ... args)
		: value(std::forward<U>(n)),
		  base(std::forward<Ts>(args)...) 
	{
	}


	static constexpr int N = base::N + 1;
};


int main()
{
	tuple<int, double, short> t3(1, 3.4, 2);
}