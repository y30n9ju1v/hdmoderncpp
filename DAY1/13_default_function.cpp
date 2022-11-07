// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무일도 하지 않은 인자가 없는 생성자가 필요하면
	// => 2번이 무조건 좋습니다. 2번 사용하세요.
//	Point() {}			// 1. 직접 사용자가 만든다.
						//    컴파일러는 구현의 내용을 알수 없습니다

	Point() = default;	// 2. 컴파일러에게 요청한다.
						//    컴파일러가 구현의 내용을 정확히 알게 됩니다.
						//    최적화가 더욱 잘됩니다.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}

// godbolt.org 에 접속해 보세요
// => C++ 코드를 어셈블리로 확인 가능한 사이트


