#include <iostream>

// 1. ������ ���ڸ� forwarding �Ϸ��� - �������� ���ø��� ����ϼ���

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f(std::forward<T>(arg)...);
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
	chronometry(f3, 1, 3.4, n);

	std::cout << n << std::endl; // 200
}
