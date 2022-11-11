// 7_�����������ø�7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// �������� ���ø��� "�������� ����"�� �ֽ��ϴ�.
// => ��ǥ���� Ȱ���� "�Ϻ��� ����" �Դϴ�.

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f( std::forward<Types>(args)... );
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

