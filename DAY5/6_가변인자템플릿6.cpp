#include <iostream>

// 233 page �Դϴ�.

// 1. 1��° ���ڴ� ������ ������ ��������

void foo() {}

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

}

int main()
{
	foo(1, 3.4, 'A'); 
}





