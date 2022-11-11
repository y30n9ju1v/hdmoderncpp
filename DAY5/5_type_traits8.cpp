#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 1 = 10;
	(n = 10) = 20;
	++n = 10;
	n++ = 10;

	// 표현식이 lvalue 인지 알고 싶다.
	// decltype(표현식) : lvalue 라면 참조 타입입니다.

	bool b = std::is_lvalue_reference_v<decltype(++n)>;

	std::cout << b << std::endl; // 1


	if (std::is_lvalue_reference_v<decltype((표현식))>)

		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}