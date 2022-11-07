// 17_static_if - 51 page

#include <iostream>
#include <type_traits>

// std::is_pointer<T>::value : T �� ������ ���� �����ϴ� ���
//							  ����ϳ� ���� �˴ϴ�.(C++11 ���)
template<typename T> 
void foo(T a)
{
	if ( std::is_pointer<T>::value )
	{
		std::cout << "������" << std::endl;

		// a�� ������ �̹Ƿ� ���� ������ �ʹ� ?
		int n = *a;
	}
	else
	{
		std::cout << "������ �ƴ�" << std::endl;
	}
}
int main()
{
	int n = 0;
	foo(n); // T = int
}

