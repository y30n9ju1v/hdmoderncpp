#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// args 에서 2번째 요소를 한번에 꺼내는 방법은 없습니다.

	// 1. pack expansion 을 사용하거나
	// 2. 재귀 호출 유사 기술을 사용할수 밖에 없습니다.


	// 모든 요소의 타입이 같으면 "배열 같은 곳에 담으세요"
	int x[] = { args... };

	// 타입이 다르면 "tuple" 에 담으세요
	std::tuple<Types...> t(args...);

	// 그런데, 실전에서는 "모든 요소를 꺼낼일은 별로 없습니다."
	// => 예제 참고.
}


int main()
{
	foo(1, 2, 3);
}

