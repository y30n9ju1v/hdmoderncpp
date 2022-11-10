#include <iostream>
#include <thread>
#include "stopwatch.h"

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw(true); // 생성자에서 시간 기록
						// 소멸자에서 걸린시간 출력
						// (true 는 소멸자에서 출력해달라는 의미)
						//  false 라면 출력 안됨

	return f(std::forward<T>(arg)...);
}

void foo(int n, double d) 
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
}
int main()
{
	chronometry(foo, 1, 3.4); // foo(1, 3.4)
}
