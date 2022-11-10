#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 핵심 : 인자 한개 를 완벽한 전달을 하려면
// 1. 인자를 받을때 "T&&" 로 받으세요 - forwarding reference
// 
// 2. 인자를 다른 함수에 전달(forward) 할때 
//    "std::forward<T>(arg)"로 묶어서 보내세요. 
//	  "static_cast<T&&>(arg)" 로 해도 됩니다.
// 
//	  => 필요한 이유 : rvalue 를 chronometry로 보낸는데.. 
//				     받으면서 lvalue(arg) 가 된것을 
//				     다시 rvalue 로 변경하기 위한것


template<typename F, typename T>
void chronometry(F f, T&& arg)
{	
	f( std::forward<T>(arg) ); 
}


int main()
{
	int n = 0;
	chronometry(goo, n);	
	chronometry(foo, 10);	
}
