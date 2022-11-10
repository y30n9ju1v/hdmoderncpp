// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0
{								// foo(arg) 는 에러! 					

								// std::nullptr_t&& arg = nullptr;
								// foo(arg) 는 ok..
	f(std::forward<T>(arg));
}

// 핵심 : 완벽한 전달을 기술을 사용하는 함수에 포인터값을 보낼때는
//      "0" 을 사용하면 에러 입니다.
//	    반드시 "nullptr" 을 사용하세요

void foo(int* p) {}

int main()
{
	foo(0); // ok

//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok

}









