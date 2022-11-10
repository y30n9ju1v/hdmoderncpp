#include <iostream>

// 함수객체와 const member function

struct Plus
{
	// 핵심 : 함수 객체를 만들때, 되도록 이면 operator() 멤버함수를
	//       상수 멤버 함수 로 하세요
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

//template<typename T> void foo(T f)
template<typename T> void foo(const T& f)
{
	int ret = f(1, 2);	// f.operator()(1, 2) 가 되어야 하는데
						// f는 상수 객체 입니다.
						// 호출 가능하게 하려면
						// "operator()" 함수를 상수 멤버 함수로해야합니다.
}

int main()
{
	Plus p;

	foo(p);
}
