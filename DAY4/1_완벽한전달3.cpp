// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

// 아래 구현은 단 한가지의 문제가 있습니다... 
// main 함수의 코드가 왜 에러인지 생각해 보세요.
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // 왜 에러일까요 ???
						  	
}
