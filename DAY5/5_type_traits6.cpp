// 4_type_traits3 - 210 page
#include <iostream>

// 핵심 1. 표준  traits 를 사용하려면
#include <type_traits>	// C++11 이후

template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T> void foo(T a)
{
	// 핵심 2. 조사하려면
	bool b1 = std::is_pointer<T>::value; // C++11 스타일
	bool b2 = std::is_pointer_v<T>;		 // C++17 스타일

	// 핵심 3. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;  // C++11
	remove_pointer_t<T> n2; // 위와 동일한 코드!  // C++14


	
}




int main()
{
	int n = 0;
	foo(&n);
}
