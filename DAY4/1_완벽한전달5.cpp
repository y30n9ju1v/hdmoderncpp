// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 핵심 : int 타입 인자 한개를 완벽히 전달하려면
// 1. int&, int&& 버전의 함수를 각각 제공
// 2. rvalue reference(int&&) 버전은 "rvalue 로 캐스팅"해서 전달

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}


int main()
{
	hoo(10);
	chronometry(hoo, 10);
}
