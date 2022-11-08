// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	// 임시객체 특징 정리.
	// 특징 1. 임시객체는 lvalue 가 될수 없다.(rvalue 이다.)
	pt.x = 10;			// ok	
	Point(1, 2).x = 10;	// error. 임시객체는 등호의 왼쪽에 올수 없다.
						// 하지만 상수는 아니다.
						
//	Point(1, 2).set(10, 20); // 이렇게해서 변경할수 는 있다.


	// 특징 2. 임시객체는 주소 연산자로 주소를 구할수 없다.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error.
							

	// 특징 3. 임시객체를 non-const reference 로 가리킬수 없다.
	// 단, const reference 로는 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	const Point& r3 = Point(1, 2);	// ok
			// 이 경우 임시객체의 수명이 r3의 수명으로 연장되게 됩니다.
			// life-time extension

	r3.x = 10; // 단, r3는 상수이므로 변경은 안됩니다.


	// C++11 에서는 상수성 없이 임시객체를 가리키고 싶었습니다
	Point&& r4 = Point(1, 2); // 내일 주요 주제.!
}





