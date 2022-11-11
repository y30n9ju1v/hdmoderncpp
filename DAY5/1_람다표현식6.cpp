// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 1. return 문장이 한개라면 return 타입 생략 가능합니다
	auto f2 = [](int a, int b) { return a + b; };


	// 2. return 문장이 2개라도 같은 타입이면 생략 가능
	auto f2 = [](int a, int b) { if (a == 1) return a;  return b; };

	// 3. return 문장이 2개인데, 다른  타입이면 생략 할수 없습니다.
	// 아래 코드는 에러
	auto f3 = [](int a, double b) { if (a == 1) return a;  return b; };

}

