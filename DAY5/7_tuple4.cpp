// Step3. 여러개 보관 하기. - 핵심 !!!

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
	tuple(const T& n, const Types&& ... args ) 
		: value(n), base(args...) {}

	static constexpr int N = base::N + 1;
};


int main()
{
//	tuple<> t0;						// 보관하는요소 없음
//	tuple<short> t1;				// short  값만 보관
//	tuple<double, short> t2;		// double 값만 보관
//	tuple<int, double, short> t3;	// int    값만 보관
	tuple<int, double, short> t3(1, 3.4, 2);
}