#include <iostream>
#include <type_traits>

// ���� : is_pointer �����ؼ� �Ʒ� �ڵ� ����ǰ� ����� ������..

template<typename T> void foo(T& a)
{
	// is_array ����� ������
	if ( is_array<T>::value ) 
		std::cout << "�迭" << std::endl;
	else
		std::cout << "�迭 �ƴ�" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}