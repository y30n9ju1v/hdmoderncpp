#include <iostream>

// nullptr 의 원리

void f1(int* p) {}
void f2(char* p) {}

// nullptr의 역사
// 1. boost 라이브러리에서 아래 처럼 만들어서 사용했습니다.
//    => 이당시 nullptr 은 nullptr_t 타입의 객체 였습니다.

// 2. C++11 만들때 표준에 도입
//   => 현재 "nullptr" 은 키워드 입니다.
//   => 타입은 "std::nullptr_t" 타입


struct mynullptr_t
{
	// 변환 연산자 함수 : 객체가 다른 타입으로 변환되려고 할때 호출.
//	operator int* () const { return 0; }
//	operator char* () const { return 0; }

	// 아래 멤버 함수 덕분에 mynullptr_t 는 모든 타입의 포인터로 
	// 암시적 형변환 가능합니다.
	template<typename T>
	operator T* () const { return 0; }
};
mynullptr_t mynullptr;


int main()
{
	f1(mynullptr);	// nullptr_t => int*로의 암시적 형변환 필요
					// "mynullptr.operator int*()" 라는 함수 호출
	f2(mynullptr);
}
