#include <iostream>
#include <type_traits>

// lvalue, rvalue 를 조사하는 방법
// decltype(표현식) : 표현식이 lvalue 가 될수 있다면 참조타입으로 결정
//					        lvalue 가 될수 없다면 값타입으로 결정

#define print_value_category( ... )	\
	if ( std::is_lvalue_reference<decltype(( __VA_ARGS__ ))>::value )	\
		std::cout << "lvalue" << std::endl;								\
	else                                                                \
		std::cout << "rvalue" << std::endl;	

int main()
{
	int n = 10;

	print_value_category(n);   // lvalue
	print_value_category(n+1);
	print_value_category(10);
	print_value_category(++n); // lvalue
	print_value_category(n++);
	
	// 정수, 실수 리터럴은 rvalue 인데
	// 문자열 리터럴은 lvalue 로 분류 됩니다.
	print_value_category("hello"); // lvalue

//	"hello"[0] = 'A'; // error 인데. rvalue 라서 에러가 아니라!
					  // const 이기 때문에  에러 입니다.
}
// 핵심 : 임시객체와 리터럴이 rvalue 라는 것만 기억해 주세요!!