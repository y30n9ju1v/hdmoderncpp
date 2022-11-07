// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>
#include <ranges>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// 반복자를 얻는 방법
	// 1. C++98 스타일
	// 단점 : 컨테이너 교체시, 반복자 타입도 변경되어야 합니다.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();


	// 2. C++11 스타일. auto 사용
	// => 컨테이너 변경시 반복자 타입이 자동으로 변경됨
//	auto p1 = v.begin(); // 이 코드는
//	auto p2 = v.end();   // v 가 raw array 라면 error

	// 멤버 함수 begin 보다 일반 함수 begin 이 유연성이 좋습니다.
	// => v가 raw array 인 경우에도 잘 동작 합니다.
	auto p1 = std::begin(v); 
	auto p2 = std::end(v);   

//	auto sz1 = v.size();	 // 배열은 에러
	auto sz2 = std::size(v); // 배열도 가능


	// C++20 에서 새로운 begin 이 등장 합니다.
	auto p3 = std::ranges::begin(v); // C++20

	// 새로운 begin 을 만든 이유..
	// => 아래 코드를 잘생각해 보세요
	auto p4 = std::begin( std::vector<int>{1, 2, 3} );

	int n1 = *p4;	// runtime error
					// 컨테이너는 이미 파괴 되었다.

	auto p5 = std::ranges::begin(std::vector<int>{1, 2, 3});
	int n2 = *p5; // 컴파일 에러
					// p5 의 타입은
					// "std::dangling_iterator" 라는 타입입니다.
					// C++20 에서 새로 만든 개념입니다.
}