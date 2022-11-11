#include <iostream>

// 233 page �Դϴ�.

// 1. 1��° ���ڴ� ������ ������ ��������

void foo() {} // C++14 �������� ����� ���Ḧ ����

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

	// C++17 ���Ŀ��� �Ʒ� ó�� �ϼ���
	if constexpr (sizeof...(args) > 0)
		foo(args...);

}

int main()
{
	foo(1, 3.4, 'A'); 
}





