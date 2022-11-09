#include <iostream>
#include <type_traits>

// lvalue, rvalue 를 조사하는 방법
// decltype(표현식) : 표현식이 lvalue 가 될수 있다면 참조타입으로 결정
//					        lvalue 가 될수 없다면 값타입으로 결정

#define print_value_category( ... )	\
	if ( std::is_lvalue_reference<decltype(( __VA_ARGS__ ))>::value )
		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;	

int main()
{
	int n = 10;


	if ( std::is_lvalue_reference<decltype(( n ))>::value )
		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}