// Step2. �Ѱ����� �����ϱ� ���� �κ� Ư��ȭ!

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& n) : value(n) {}

	static constexpr int N = 1;
};


int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}