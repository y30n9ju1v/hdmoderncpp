#include <iostream>

// 1. 여러개 인자를 forwarding 하려면 - 가변인자 템플릿을 사용하세요
// 2. 반환값도 완벽하게 돌려 주려면 - decltype(auto) 반환 사용하세요.

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)...);
}

void f0() {}
void f2(int a, double d) {}
int& f3(int a, double d, int& r)
{
	std::cout << "r3" << std::endl;
	r = 200;
	return r;
}

int main()
{
	int n = 0;
	chronometry(f0);
	chronometry(f2, 1, 3.4);
	int& ret = chronometry(f3, 1, 3.4, n); // f3(1, 3.4, n)

	std::cout << n << std::endl; // 200
}
