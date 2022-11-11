#include <iostream>

// �Ϲ� �Լ� ���ڷ� auto �� ����ϴ� ���� "C++20" ���� ���� �մϴ�
// C++17 ������ ���� �Դϴ�.
// void foo(auto n) {} 

int main()
{
	// generic lambda
	// C++14 ���� ����ǥ������ ���ڷ� "auto" ��밡���մϴ�.
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 1);
	double d3 = f(1, 3.2);

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
}

