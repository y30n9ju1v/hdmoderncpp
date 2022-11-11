#include <iostream>
#include <type_traits> // �� �ȿ� ���ʰ��� traits �� �ֽ��ϴ�.

// type traits
// => Ÿ�Կ� ���� �پ��� Ư��(Ư��)�� �����ϴ� ���
// => ���ø� ���鶧 �θ� ���

template<typename T> struct is_pointer
{
	static constexpr bool value = false;
};
// �ٽ� : ������ �����ϴ� Ÿ���� ���� "�κ� Ư��ȭ"�� �ۼ��ϰ�
//       value = true
template<typename T> struct is_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// ���� T �� "int", "int*"
//	if ( is_pointer<T>::value )
	if ( std::is_pointer<T>::value)

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