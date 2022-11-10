#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&


	int&& r2 = 10;	// 이 코드에서
					// "10" 은 rvalue 이지만
					// r2 는 lvalue 입니다.

	foo(r2);	// int&

	// 타입과 value 속성을 잘 구별하세요
	//			타입			value 속성
	// n		int			lvalue
	// n+1		int			rvalue
	// 10		int			rvalue
	// r1		int&		lvalue
	// r2		int&&		lvalue

	foo(r2); // int&
	foo(static_cast<int&&>(r2)); // int&&
		// => r2 가 int&& 타입이므로 결국 같은 타입 캐스팅 아닌가요 ?
		// => 위 캐스팅은 타입 캐스팅이 아닙니다.
		// => value 속성을 변경하는 캐스팅 입니다.
		//    lvalue => rvalue(정확히는 xvalue) 로 캐스팅하는 것입니다.
		// cppreference.com 에서 static_cast 찾아보세요
}
void f1(int&) {}	// "int&" 타입을 받겠다는 것이 아니라
					// lvalue 를 받겠다는 것
void f1(int&&) {}	// "int&&" 타입을 받겠다는 것이 아니라
					// rvalue 를 받겠다는 것





