#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1,2,3 인데
	// args 의 모든 요소에대해서 printv 를 사용하고 싶다.

//	printv(args...); // printv(1,2,3) 이므로 에러!

//	printv(args)...; // 의도 : printv(1), printv(2), printv(3)
					 // error

	// 핵심 : pack expansion 은 모든 위치에서 가능한 것은 아닙니다.
	// 1. 함수 호출시 () 안
	// 2. {} 초기화 구문 안에서만 가능

	int x[] = { (printv(args), 0)... }; 
		   // { (printv(1),0), (printv(2),0), (printv(3),0) };
}


int main()
{
	foo(1, 2, 3);
}

