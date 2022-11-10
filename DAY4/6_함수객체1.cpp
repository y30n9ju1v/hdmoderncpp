#include <iostream>
// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체
// => functor 라고도 합니다.

// 왜 ? 함수를 사용하지 않고 함수 객체를 사용하나요 ?
// 1. 상태를 가지는 함수. "클로져"
// 2. 특정 상황에서 함수 보다 빠릅니다.
// 3. namespace ADL 에 적용 안됨. 

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p;			// p 는 함수가 아닌 Plus 타입의 "객체" 입니다

	int n = p(1, 2);// 객체인 p 를 함수 처럼 사용합니다.
					// "함수 객체" 라고 합니다.

	int n2 = p.operator()(1, 2);// 이렇게 사용해도 됩니다.
	
}


