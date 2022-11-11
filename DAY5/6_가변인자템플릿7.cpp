// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 가변인자 템플릿은 "전형적인 패턴"이 있습니다.
// => 대표적인 활용이 "완벽한 전달" 입니다.

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f( std::forward<Types>(args)... );
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

