#include <iostream>
#include <type_traits>

// type traits
// => Ÿ�Կ� ���� �پ��� Ư��(Ư��)�� �����ϴ� ���
// => ���ø� ���鶧 �θ� ���

template<typename T> struct is_pointer
{
	static constexpr bool value = false;
};

template<typename T> void foo(const T& a)
{
	if ( is_pointer<T>::value )
		std::cout << "������" << std::endl;
	else
		std::cout << "������ �ƴ�" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}