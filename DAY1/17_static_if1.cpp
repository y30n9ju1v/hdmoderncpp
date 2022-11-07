// 17_static_if - 51 page

#include <iostream>
#include <type_traits>

// std::is_pointer<T>::value : T 가 포인터 인지 조사하는 기술
//							  목요일날 배우게 됩니다.(C++11 기술)
template<typename T> 
void foo(T a)
{
	if ( std::is_pointer<T>::value )
	{
		std::cout << "포인터" << std::endl;

		// a가 포인터 이므로 값을 꺼내고 싶다 ?
		int n = *a;
	}
	else
	{
		std::cout << "포인터 아님" << std::endl;
	}
}
int main()
{
	int n = 0;
	foo(n); // T = int
}

