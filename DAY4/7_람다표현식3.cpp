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
	// => 람다 표현식은 "임시객체(rvalue)" 입니다. 

	auto  a1 = [](int a, int b) { return a + b; };	// ok

	auto& a2 = [](int a, int b) { return a + b; };	// error

	const auto& a3 = [](int a, int b) { return a + b; }; // ok

	auto&& a4 = [](int a, int b) { return a + b; };	// ok
	// forwarding reference !!

	// 위 4개중 제일 좋은 코드는 "a1" 입니다.
	CompilerGenratedName a1 = CompilerGenratedName(); // 인데
				// 복사(move) 생성자 최적화 에 의해서 아래코드 처럼됩니다.

	CompilerGenratedName a1; 
}

