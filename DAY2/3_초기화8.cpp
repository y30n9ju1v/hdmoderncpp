// 1_초기화8 - 62page
#include <iostream>
#include <initializer_list> // 핵심

// list       : 떨어진 메모리, 요소가 힙
// vector     : 연속된 메모리, 요소가 힙
// std::array : 연속된 메모리, 요소가 스택도 가능, 요소 소유
// std::initializer_list : 연속된 메모리, 요소가 스택도 가능, 
//							시작 주소와 마지막 다음주소(또는 개수)만관리

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// C++11 에서 초기화를 위해 만든 타입
	// => 내부적으로 "포인터 2개(vc)" 또는 "포인터 한개 + 갯수-g++" 로
	//    되어있습니다. 
	// => 데이타 자체는 함수 안에서 만들면 stack 에 놓이게 됩니다.
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// STL 처럼 반복자를 얻어서 요소에 접근할수 있습니다.
	auto p1 = e.begin();
	auto p2 = e.end();
	
	foo(e);
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3,4,5, 6, 7,8 }); 
		// => 함수 인자로 initializer_list 를 받으면
		//	  동일 타입의 객체를 몇개라도 보낼수 있습니다.

		// => initializer_list 는 사용자가 유사하게 만들수 없습니다.
		//    컴파일러의 도움이 필요 합니다. 컴파일러가 인식하는 타입
}


