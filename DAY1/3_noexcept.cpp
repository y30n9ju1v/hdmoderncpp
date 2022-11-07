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
	bool b1 = noexcept(foo()); // false
	bool b2 = noexcept(goo()); // true
	bool b3 = noexcept(hoo()); // false
	 
	std::cout << b1 << std::endl; // 0
	std::cout << b2 << std::endl; // 1
	std::cout << b3 << std::endl; // 0
}
// 함수가 예외가 없다면 되도록 "noexcept" 를 붙이세요
// 1. 컴파일러 최적화가 더 잘지원 됩니다.
// 2. noexcept 가 꼭 필요한 경우가 있습니다. - move, swap, 소멸자
//										내일 배웁니다.
							// 단, 소멸자는 noexcept를 붙이지 않아도
							// 디폴트가 noexcept 입니다.




