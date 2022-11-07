// 17_static_if - 51 page

#include <iostream>
#include <type_traits>

// std::is_pointer<T>::value : T 가 포인터 인지 조사하는 기술
							  //목요일날 배우게 됩니다.(C++11 기술)


template<typename T> 
void foo(T a)
{
	// 기존의 if : 실행시간 제어문
	//		      컴파일 시간에 결과가 false 가 되어도
	//		      "템플릿" => "C++함수" 로 만들때 코드가 포함됨.
//	if ( std::is_pointer<T>::value )

	// C++17 의 "static if" : 조건이 false 라면
	//						 템플릿 으로 부터 생성되는 함수에는 포함안함
	if constexpr (std::is_pointer<T>::value)
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

