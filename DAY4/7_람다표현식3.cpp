#include <iostream>

// auto 와 람다 표현식
int main()
{
	// 핵심 1. 람다표현식의 최종 결과는 임시객체 입니다.
	// 핵심 2. 람다 표현식을 auto 변수에 담아서 함수 처럼 사용가능.

	auto f = [](int a, int b) { return a + b; };
			// class xxx{ operator()() }; xxx();

	int n1 = f(1, 2);
	int n2 = f.operator()(1, 2); // 이렇게도 가능합니다.


	// 핵심 3. 다음중 에러를 모두 고르세요!

	auto  a1 = [](int a, int b) { return a + b; };
	auto& a2 = [](int a, int b) { return a + b; };

	const auto& a3 = [](int a, int b) { return a + b; };

	auto&& a4 = [](int a, int b) { return a + b; };	

}

