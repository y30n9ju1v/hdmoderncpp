template<typename T> void f1(T a, T b)
{
}
template<typename T> void f2(T& a, T& b)
{
}

int main()
{
	f1("orange", "apple"); // ok
	f2("orange", "apple"); // error. �� �����ϱ�� ?
}