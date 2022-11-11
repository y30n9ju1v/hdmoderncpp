// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수
	// => 전역변수는 프로그램의 어디에서도 접근가능하다.
	// => 따라서, 람다 표현식안 에서도 사용 가능
	auto f1 = [](int a) { return a + g; }; // ok

	// 2. 람다표현식 안에서 main 지역변수 접근
	auto f2 = [](int a) { return a + v1 + v2; }; // error

	// 3. 지역변수를 캡쳐하면 접근 가능하다.
	auto f3 = [v1, v2](int a) { return a + v1 + v2; }; // ok

	// 4. 값으로 캡쳐된 지역변수는 수정할수 없다.
	auto f4 = [v1, v2](int a) { v1 = 200; }; // error
}





