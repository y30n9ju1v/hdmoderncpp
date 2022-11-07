#include <iostream>

template<typename T> class Base
{
public:
	// 아래 코드는 "a" 가 const 입니다.
	//virtual void foo(const T a) // 이 코드와
	virtual void foo(T const  a)  // 이 코드는 동일합니다.
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// 가상함수 재정의시 override 붙이지 말고 해보세요.
	// 아래 코드는 "a" 는 const 가 아닙니다.
	// "a 가 가리키는 곳"이 const 입니다.
	//virtual void foo(const int* a) 

	virtual void foo( int* const a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 해보세요.
}

// 위코드가 어려우신 분은 아래 3줄 C언어에서 찾아 보세요
int n = 0;
const int* p1 = &n;
int const* p2 = &n;
int* const p3 = &n;