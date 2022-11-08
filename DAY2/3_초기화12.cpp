// 3_초기화12
#include <iostream>
#include <array> // C++11 array 컨테이너

// C++11 array 구현을 생각해 봅시다.
template<typename T, std::size_t sz>
struct array
{
	T buff[sz];

	// array 는 aggregate 타입이어야 합니다.
	// "생성자", "복사 생성자", "이동 생성자" 모두 만들면 안됩니다.
	// 
//	array() {}
//	array(const array&) {} // 복사 생성자도 "생성자"의 종류 입니다.
};

int main()
{
	// std::array 은 aggregate 타입이기때문에 아래 처럼 사용가능합니다
	array<int, 5> arr = { 1,2,3,4,5 };


}