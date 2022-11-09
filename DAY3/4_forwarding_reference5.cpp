#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법 - 아래 처럼 해도 되고
	std::cout << __FUNCSIG__ << std::endl;

	// godbolr.org에 이코드를 넣어 보세요..
}

int main()
{
	int n = 10;

	// forwarding reference 사용시
	// 인자에 따라 T 가 어떤 타입이 되는지 명확히 알아야 합니다.
	foo(n);  // T=int&    arg : T&& => int& && => int&
	foo(10); // T=int     arg : T&& => int&&
}




