#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;
public:
	Point(int a, int b) {}

	Point() {}			
//	Point() = default;	
};

int main()
{
	Point p1{}; // 내일 배우는 value initailization 개념
				// 모든 멤버를 0으로 초기화
				// => 단, 사용자가 생성자 구현을 제공하지 않는 경우만
				//	  즉, "= default"

	std::cout << p1.x << std::endl; // ok
}



