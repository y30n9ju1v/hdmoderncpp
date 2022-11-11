// 4_type_traits - 184page

#include <iostream>
#include <type_traits>

template<typename T> void printv(const T& v)
{
	// if          : 실행시간 조건문
	// if consexpr : 컴파일시간 조건문
	//				 조건이 false 라면. 
	//				 템플릿으로 부터 C++ 함수를 생성할때 포함 안됨.!
//	if ( std::is_pointer_v<T> )

	if constexpr (std::is_pointer_v<T>)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}


