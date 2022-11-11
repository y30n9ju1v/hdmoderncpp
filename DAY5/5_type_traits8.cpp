#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 1 = 10;
	(n = 10) = 20;
	++n = 10;
	n++ = 10;

	// ǥ������ lvalue ���� �˰� �ʹ�.
	// decltype(ǥ����) : lvalue ��� ���� Ÿ���Դϴ�.

	bool b = std::is_lvalue_reference_v<decltype(++n)>;

	std::cout << b << std::endl; // 1


	if (std::is_lvalue_reference_v<decltype((ǥ����))>)

		std::cout << "lvalue" << std::endl;
	else
		std::cout << "rvalue" << std::endl;
}