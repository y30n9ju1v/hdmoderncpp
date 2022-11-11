#include <iostream>

// 233 page 입니다.

// 1. 1번째 인자는 독립된 변수에 담으세요

void foo() {} // C++14 까지에서 재귀의 종료를 위해

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

	// C++17 이후에는 아래 처럼 하세요
	if constexpr (sizeof...(args) > 0)
		foo(args...);

}

int main()
{
	foo(1, 3.4, 'A'); 
}





