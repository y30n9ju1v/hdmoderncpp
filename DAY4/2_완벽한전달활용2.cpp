#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ? 2번
	// => new Point(1,2)
	// => new 관리객체;
//	std::shared_ptr<Point> sp1(new Point(1,2));


	// C++ 표준 shared_ptr 을 사용할때는
	// "std::make_shared" 로 만드는 것이 좋습니다.(강력권장)
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);
}







