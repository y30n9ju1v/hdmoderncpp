#include <iostream>
#include <functional>
#include <vector>
#include "stopwatch.h"

inline bool cmp(int a, int b) { return a < b; }

struct CMP
{
	inline bool operator()(int a, int b) { return a < b; }
};

std::vector<int> v1(1000000, 0);
std::vector<int> v2(1000000, 0);
std::vector<int> v3(1000000, 0);


void task1()
{
	CMP cp;
	std::sort(v1.begin(), v1.end(), cp);
}

void task2()
{
	std::sort(v2.begin(), v2.end(), cmp);
}

void task3()
{
	std::sort(v3.begin(), v3.end(), [](int a, int b) {return a < b; });
}

int main()
{
	chronometry(task1);
	chronometry(task2);
	chronometry(task3);
}