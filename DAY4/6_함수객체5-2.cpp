// 6_ÇÔ¼ö°´Ã¼5 - 2
#include <iostream>
#include <algorithm>
#include "stopwatch.h"

constexpr int size = 1000000;
int x[size] = { 0 };

inline void foo(int n)
{
	static int s = 0;
	s += n;
}

struct FOO
{
	inline void operator()(int n) const
	{
		static int s = 0;
		s += n;
	}
};

void task1()
{
	std::for_each(x, x + size, foo);
}
void task2()
{
	FOO f;
	std::for_each(x, x + size, f);
}
int main()
{
	chronometry(task1);
	chronometry(task2);
}