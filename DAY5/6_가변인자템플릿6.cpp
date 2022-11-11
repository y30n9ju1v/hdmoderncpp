#include <iostream>

// 233 page 입니다.

// 1. 1번째 인자는 독립된 변수에 담으세요

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





