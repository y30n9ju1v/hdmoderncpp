// Step3. ������ ���� �ϱ�. - �ٽ� !!!

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
//	tuple<> t0;						// �����ϴ¿�� ����
//	tuple<short> t1;				// short  ���� ����
//	tuple<double, short> t2;		// double ���� ����
//	tuple<int, double, short> t3;	// int    ���� ����
	tuple<int, double, short> t3(1, 3.4, 2);
}