// 8_nullptr2
#include <iostream>

// 왜 nullptr을 만들었나 ?

template<typename F, typename T>
void forward_argument(F f, T arg)	// int arg = 0; 일때
{									// foo(arg) 이므로 에러
									// std::nullptr_t arg = nullptr
	f(arg);							// foo(arg) 는 ok.. 
}
void foo(int*) { std::cout << "foo" << std::endl; }

int main()
{
	foo(0);	// ok

	int n = 0;
//	foo(n); // error. 리터럴 '0' 은 포인터로 암시적 형변환 되지만
			// 0으로 초기화된 정수형 변수는 포인터로 암시적 변환될수
			// 없습니다.

//	forward_argument(foo, 0); // 의도 "foo(0)" 처럼 호출해 달라
							  // 하지만 에러!!!
	forward_argument(foo, nullptr); // ok
}







