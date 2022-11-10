#include <iostream>
#include <thread>
#include "stopwatch.h"

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw(true); // �����ڿ��� �ð� ���
						// �Ҹ��ڿ��� �ɸ��ð� ���
						// (true �� �Ҹ��ڿ��� ����ش޶�� �ǹ�)
						//  false ��� ��� �ȵ�

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
