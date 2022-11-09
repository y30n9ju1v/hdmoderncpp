#include <iostream>
#include <type_traits>

// lvalue, rvalue �� �����ϴ� ���
// decltype(ǥ����) : ǥ������ lvalue �� �ɼ� �ִٸ� ����Ÿ������ ����
//					        lvalue �� �ɼ� ���ٸ� ��Ÿ������ ����

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
	
	// ����, �Ǽ� ���ͷ��� rvalue �ε�
	// ���ڿ� ���ͷ��� lvalue �� �з� �˴ϴ�.
	print_value_category("hello"); // lvalue

//	"hello"[0] = 'A'; // error �ε�. rvalue �� ������ �ƴ϶�!
					  // const �̱� ������  ���� �Դϴ�.
}
// �ٽ� : �ӽð�ü�� ���ͷ��� rvalue ��� �͸� ����� �ּ���!!