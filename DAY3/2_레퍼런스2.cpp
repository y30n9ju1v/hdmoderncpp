#include <iostream>

// 90 page

// 아래 처럼 함수 오버로딩 가능합니다.
void foo(int& a)       { std::cout << "1 int&" << std::endl; }
void foo(const int& a) { std::cout << "2 const int&" << std::endl; }
void foo(int&& a)      { std::cout << "3 int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n);		// lvalue 이므로 1, 2 모두 가능한데
				// (1)이 선택됩니다. (1)이 없으면 (2) 호출

	foo(10);	// 10 은 rvalue 이므로, 2, 3 모두 가능한데
				// (3)이 선택됩니다. (3)이 없으면 (2) 호출

}







