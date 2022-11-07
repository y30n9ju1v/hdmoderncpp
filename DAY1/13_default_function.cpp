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
	Point() = default;	// 2. 컴파일러에게 요청한다.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




