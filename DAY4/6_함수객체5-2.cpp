// 6_ÇÔ¼ö°´Ã¼5 - 2
#include <iostream>
#include <algorithm>
#include "stopwatch.h"

inline void foo(int n)
{
	static int s = 0;
	s += n;
}

constexpr int size = 1000000;
int x[size] = { 0 };

void task1()
{
	std::for_each(x, x + size, foo);
}
int main()
{
	chronometry(task1);
}