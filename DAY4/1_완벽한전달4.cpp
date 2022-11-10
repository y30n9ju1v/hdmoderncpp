// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// main					chronometry					hoo(int&&)
// hoo(10) =============================================> ok
// chronometry(10)  ====> int&& arg로 받기
//					      hoo(arg) =====================> error
//						  hoo(static_cast<int&&>(arg))==> ok.

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	// 인자를 받을때 
	// "int&& arg = 10" 인데. 이때 "10" 은 rvalue 지만
	//						 arg 는 "lvalue" 입니다.
//	f(arg);	// hoo(int&) 를 찾게 됩니다.

	// 원래 인자는 "rvalue" 였는데, 받으면서 이름이 생겨서 lvalue 가된것
	// 함수에 전달할때는 다시 rvalue 로 변경해서 전달합니다.
	f(static_cast<int&&>(arg)); // hoo(int&&) 로 전달
}

int main()
{
	hoo(10); 
	chronometry(hoo, 10); 
}
