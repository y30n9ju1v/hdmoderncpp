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
	// 핵심 1. 아래 캐스팅은 절대 "rvalue 캐스팅"이 아닙니다.
	//        chronometry(함수, n)  : static_cast<int&>(arg)
	//        chronometry(함수, 10) : static_cast<int&&>(arg)

	// 즉, 
	// (인자로) lvalue 를 (전달하면) lvalue 로 캐스팅하고
	//         rvalue 를 (전달하면  받으면서 lvalue 가된 것을 ) 
	//								다시 rvalue 로 캐스팅 합니다.
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // 이 함수가 하는 일이
							// 위 캐스팅 입니다.
							// "T&&" 가 아니라 "T" 로 전달하면됩니다.
}

int main()
{
	int n = 0;
	chronometry(goo, n);	// T=int&,  T&&=int& && => int&
							// 함수 모양 : chronometry(F f, int& )
							// 캐스팅 모양: static_cast<int&>(arg);

	chronometry(foo, 10);	// T=int,  T&&=int&&
							// 함수 모양 : chronometry(F f, int&& )
							// 캐스팅 모양: static_cast<int&&>(arg);
}
