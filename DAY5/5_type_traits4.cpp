// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

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
	// remove_pointer 를 T에 의존해서 사용한다면 
	// typename 꼭 표기 하세요

//	remove_pointer<T>::type n1; // error
	typename remove_pointer<T>::type n1; // ok. 
}