#include <iostream>

// 규칙 1. 템플릿 파라미터가 "값 타입(T a)" 일때
// => 함수인자가 가지는 const, volatile, reference 를 제거하고
//    타입을 결정

template<typename T> void foo(T a)
{
//	a = 100;
	// T의 타입을 확인 하는 방법 1. C++ RTTI 기술 사용
	// => reference, volatile 기호가 표시되지 않습니다.
	// => 정확하지 않습니다. 사용하지 마세요
	// std::cout << typeid(T).name() << std::endl;

	// 함수 이름을 출력하는 매크로를 사용하세요
	// VC++ : __FUNCSIG__
	// g++  : __PRETTY_FUNCTION__
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	// 사용자가 타입 전달, 컴파일러는 타입 추론하지 않음.
	// => 사용자가 전달한 타입 사용
	foo<int>(3);

	// 타입을 전달하지 않으면 함수 인자로 타입 추론
	foo(10);	// T=int
	foo(3.4);	// T=double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n); // T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int

	// 포인터도 결국은 값입니다.(주소값)
	// => 주의 ! 인자의 const 만 제거 됩니다.
	// => 아래 코드에서 "s1" 은 const 아닙니다. s1이 가리키는 곳이 const
	const char* s1 = "hello";
	foo(s1); // T = const char*

	const char* const s2 = "hello";
	foo(s2); // T = const char*
			 //     char const* 와 동일
			 //     char* const 이 표현이 다른 타입(포인터 자체가 const)
}