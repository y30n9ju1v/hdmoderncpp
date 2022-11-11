#include <iostream>
#include <type_traits>

// 과제 : is_pointer 참고해서 아래 코드 실행되게 만들어 보세요..

template<typename T> void foo(T& a)
{
	// is_array 만들어 보세요
	if ( is_array<T>::value ) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int arr[3] = { 1,2,3 };
	foo(arr);
}