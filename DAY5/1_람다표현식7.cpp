#include <iostream>

// 일반 함수 인자로 auto 를 사용하는 것은 "C++20" 부터 지원 합니다
// C++17 까지는 에러 입니다.
// void foo(auto n) {} 

int main()
{
	// generic lambda
	// C++14 부터 람다표현식의 인자로 "auto" 사용가능합니다.
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 1);
	double d3 = f(1, 3.2);

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
}

