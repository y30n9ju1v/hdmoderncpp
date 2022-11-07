// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 의 의미

// 1. 함수가 예외가 없음을 컴파일러에게 알리는 것
void foo() {}		// 예외의 가능성이 있다는 의미!

void goo() noexcept // 예외가 발생하지 않는다고 컴파일러에게
{					// 알려 주는 것
}
void hoo()
{
	if (1) // 실패
		throw std::bad_alloc();
}
int main()
{
	// noexcept 의미 2. 함수가 예외가 있는지 조사
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());
	bool b3 = noexcept(hoo());

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
}




