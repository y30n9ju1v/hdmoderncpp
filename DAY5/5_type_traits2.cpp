#include <iostream>
#include <type_traits> // 이 안에 수십개의 traits 가 있습니다.

// type traits
// => 타입에 대한 다양한 특성(특질)을 조사하는 기술
// => 템플릿 만들때 널리 사용

template<typename T> struct is_pointer
{
	static constexpr bool value = false;
};
// 핵심 : 조건을 만족하는 타입을 위한 "부분 특수화"를 작성하고
//       value = true
template<typename T> struct is_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// 현재 T 는 "int", "int*"
//	if ( is_pointer<T>::value )
	if ( std::is_pointer<T>::value)

		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}
int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}