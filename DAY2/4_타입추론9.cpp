#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4); // auto 는 우변의 참조를
//  int  ret = foo(1, 3.4); // 제거하고 타입 결정


//	decltype( 함수 호출식 ) : 함수 호출의 결과로 나오는 타입.
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//  int& ret = foo(1,3.4);


	// decltype(auto) : C++14에서 추가된 표기법
	// => auto 자리에 우변 표현식을 넣어 달라.
	// => 또는, 우변으로 타입을 결정하는데, 규칙은 decltype 규칙 적용
	decltype(auto) ret3 = foo(1, 3.4);
//  int& ret3 = foo(1, 3.4);


	// 참고
	// 평가되지 않은 표현식(unevaluated expression)
	// (A) : 실제 실행되는 것은 아니고, 컴파일 시간에 함수 선언을 찾아서
	//       반환 타입만 조사 - 평가되지 않은 표현식
	// (B) : 실행시간에 실제 실행됩니다.
	//			(A)					(B)
	decltype(foo(1, 3.4)) ret5 = foo(1, 3.4);

	// C++에는 4개의 평가되지 않은 표현식이 있습니다.
	// => 평가되지 않은 표현식에 들어가는 함수는 선언만 있어도 됩니다.
	decltype(foo(1, 3.4)) d;

	bool b = noexcept(foo(1, 3.4));

	int n = sizeof((foo(1, 3.4));
	
	typeid(foo(1, 3.4)).name();
}

// int goo(int a);
// int n = sizeof(goo(3)); // 4. 에러 아님. 선언만 보면 알수 있음.

