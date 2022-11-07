// 교재 7 page
#include <cassert>

// assert : 실행시간에 표현식의 유효성을 조사
// static_assert : 컴파일 시간에 표현식의 유효성을 조사
//					C++11 부터 제공
//				   키워드 입니다. include 필요 없습니다.

// 주의 1. 함수 안 또는 함수 밖에 모두 만들수 있습니다.
//     2. 표현식은 반드시 컴파일 시간에 조사 가능해야 합니다.

static_assert(sizeof(int*) >= 8, "error not 64bit");

void foo(int age)
{
	// 함수 인자를 바로 사용하는 것 보다는
	// 인자값의 유효성을 확인하는 것이 안전하다.
	assert(age > 0);

//	static_assert(age > 0, ""); // error
								// 변수값은 컴파일 시간에
								// 조사할수 없습니다.


	// 인자가 나이 이므로
	// 나이는 "0 보다 크다" 라고 생각하고 코드 작성
	int* p = new int[age];

	delete[] p;
}
int main()
{
	foo(10);
//	foo(-10);
}