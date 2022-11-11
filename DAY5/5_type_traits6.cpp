// 4_type_traits3 - 210 page
#include <iostream>

// �ٽ� 1. ǥ��  traits �� ����Ϸ���
#include <type_traits>	// C++11 ����

template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// �ٽ� 2. �����Ϸ���
	bool b1 = std::is_pointer<T>::value; // C++11 ��Ÿ��
	bool b2 = std::is_pointer_v<T>;		 // C++17 ��Ÿ��

	// �ٽ� 3. ���� Ÿ���� ��������
	typename std::remove_pointer<T>::type n1;  // C++11
	remove_pointer_t<T> n2; // ���� ������ �ڵ�!  // C++14


	
}




int main()
{
	int n = 0;
	foo(&n);
}
