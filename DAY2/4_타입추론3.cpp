#include <iostream>

// 규칙 2. 템플릿 파라미터가 "참조(T& a)" 일때
// => 함수 인자가 가진 "reference 속성만 제거" 한후 T의 타입결정
// => const volatile 은 유지
template<typename T> void foo(T& a)
{
//	std::cout << typeid(T).name() << ", " << 
//		         typeid(a).name() <<std::endl;
			// => 잘못된 결과, reference, const, volatile 를 출력 못합니다.

	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T = int			a = int&
	foo(c);  // T = const int	a = const int&
	foo(r);  // T = int			a = int&
	foo(cr); // T = const int   a = const int&
}