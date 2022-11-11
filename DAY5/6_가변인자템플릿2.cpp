#include <iostream>

template<typename ... Types> void foo(Types ... args)
{
	// �ٽ� 1. "parameter pack" �̶�� ��� �˾� �μ���
	// Types : int, int, int => template parameter pack
	// args  : 1,   2,   3   => function parameter pack 

	// �ٽ� 2. sizeof...
	std::cout << sizeof...(args) << std::endl; // 3
	std::cout << sizeof...(Types) << std::endl; // 3
}

int main()
{
	foo(1, 2, 3);	// foo(int, int, int) �Լ� ����
}