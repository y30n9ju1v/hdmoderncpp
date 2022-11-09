#include <iostream>
#include <type_traits>

// lvalue, rvalue �� �����ϴ� ���
// decltype(ǥ����) : ǥ������ lvalue �� �ɼ� �ִٸ� ����Ÿ������ ����
//					        lvalue �� �ɼ� ���ٸ� ��Ÿ������ ����

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