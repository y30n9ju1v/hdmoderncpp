#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // 필요 없는 캐스팅 입니다.
								// 있어도 에러 아닙니다.
								// 성능저하도 없습니다.
								// 컴파일 시간에 제거 됩니다.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// 핵심 : forwarding reference(T&&) 를 사용하면 
//       모든 타입에 대해서 rvalue reference, lvalue reference 함수를
//       생성할수 있다.
//		=> 그런데, 함수 템플릿으로 만들려면 구현에 동일해야 한다.

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(goo, n);	// T=?,  T&&=?
							// 함수 모양 : chronometry(F f, ? )
							// 캐스팅 모양: static_cast<?>(arg);

	chronometry(foo, 10);	// T=?,  T&&=?
							// 함수 모양 : chronometry(F f, ? )
							// 캐스팅 모양: static_cast<?>(arg);
}
