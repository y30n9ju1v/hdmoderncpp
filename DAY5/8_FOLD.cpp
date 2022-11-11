// 9_FOLD - 237 page
#include <iostream>

// fold expression : C++17
// => parameter pack 의 모든 요소에 대해 이항 연산을 수행
// => 반드시 () 를 표기해야 합니다.


template<typename ... Types> 
int Sum(Types ... args)
{
	// ( pack이름  이항연산자 ...)
//	int s = (args + ... ); // (1 + ( 2 + 3) ) => unary right fold
	int s = (...  + args); // ((1 + 2) + 3) ) => unary left fold
		  

	return s;
}
int main()
{
	int n = Sum(1, 2, 3);

	std::cout << n << std::endl;
}



