#include <iostream>

// decltype 을 이해 하기 위해서 사전에 알아야 하는 지식 입니다.

int x = 0;

int  f1() { return x; }	// x 의 값 "0" 을 반환
int& f2() { return x; } // x 의 별명을 반환

int main()
{
	f1() = 20;	// error. "0 = 20" 의 의미 !
	f2() = 20;  // ok.    "x = 20" 의 의미

	// 핵심 : 함수가 "참조"를 반환하면 함수 호출을 등호의 왼쪽에 놓일수
	//       있습니다. ("lvalue 가 될수 있습니다.")
}