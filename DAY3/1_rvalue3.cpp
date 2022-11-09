#include <iostream>
#include <type_traits>

// lvalue, rvalue �� �����ϴ� ���
// decltype(ǥ����) : ǥ������ lvalue �� �ɼ� �ִٸ� ����Ÿ������ ����
//					        lvalue �� �ɼ� ���ٸ� ��Ÿ������ ����

int main()
{
	int n = 10;


	if ( std::is_lvalue_reference<decltype( 5 )>::value )
		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}