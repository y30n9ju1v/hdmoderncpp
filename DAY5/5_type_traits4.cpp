// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits �� ����
// 1. Ÿ������ : is_xxx<T>::value
// 2. ����Ÿ�Ծ�� : xxx<T>::type

template<typename T> struct remove_pointer
{
	using type = T;
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};
int main()
{
	remove_pointer<int*>::type n2; 

	std::cout << typeid(n2).name() << std::endl; // int
}

template<typename T> void foo(T a)
{
	// remove_pointer �� T�� �����ؼ� ����Ѵٸ� 
	// typename �� ǥ�� �ϼ���

//	remove_pointer<T>::type n1; // error
	typename remove_pointer<T>::type n1; // ok. 
}