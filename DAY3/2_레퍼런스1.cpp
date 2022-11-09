// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

void init_point(Point& pt)       
{
	// pt 가 가리키는 객체를 변경
	pt.x = 10;
	pt.y = 10;
}

void draw_point(const Point& pt) 
{
	// pt 가 가리키는 객체를 읽기만
}

void move_ctor(Point&& pt)
{
	// C++11 부터는 임시객체를 인자로 받아서 값을 수정할수 있게 되었다.
	// => 왜 임시객체를 수정해야 합니까 ??? move 를 만들기 위해!
	pt.x = 10;
}


int main()
{
	Point pt(0, 0);

	// 규칙 1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// 규칙 2. const lvalue reference 는 lvalue, rvalue 를 모두 가리킬수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok

	// 왜 문법을 위처럼 설계 했나요 ?
	// => ARM 책 참고 ( C++ annoted reference manual )


	// C++11 을 만들면서 "상수성 없이 rvalue 를 가리키고 싶었다"
	// 규칙 3. rvalue reference 는 rvalue 만 가리킨다.
	
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok 


	// 그럼. const rvalue reference 는 어떻게 되나요 ?
	// => rvalue 만 가리킬수 있습니다.
	// => 그런데, 거의 사용되지 않기 때문에 중요하지는 않습니다.
	const Point&& r7 = pt;			// error
	const Point&& r8 = Point(0, 0);	// ok 
}
