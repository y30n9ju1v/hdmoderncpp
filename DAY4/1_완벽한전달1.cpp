// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding         : 함수 가 전달받은 인자를 다른 함수에 보내는 것
// perfect forwarding : 전달 받은 인자의 어떠한 변화도 없이
//						그대로 전달하는 것

// 특정 함수의 수행시간을 측정하는 함수를 만들어 봅시다.
template<typename F, typename ARG>
void chronometry(F f, ARG arg)
{
			// 함수 호출전에 시간 기록
	f(arg);	// 함수 호출
			// 함수 수행에 소요된 시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
