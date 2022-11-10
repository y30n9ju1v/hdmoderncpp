// 6_ÇÔ¼ö°´Ã¼5 - 2
#include <iostream>
#include <algorithm>
#include "stopwatch.h"

constexpr int size = 100000000;
int x[size] = { 0 };

int s1 = 0;
int s2 = 0;

inline void foo(int n)
{
	s1 += n;
}

struct FOO
{
	inline void operator()(int n) const
	{
		s2 += n;
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
//	chronometry(task1);
	chronometry(task2);
}   