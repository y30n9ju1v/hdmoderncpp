// Step1. �������� ���ø� ���

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}