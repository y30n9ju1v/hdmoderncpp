// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 정확한 모양을 이해해 봅시다.

	// 1. call by value
	// => 인자를 받을때 모양이 "Point pt = p2" 입니다.
	// => 다시 복사생성자가 호출되는 모양
	// => 복사 생성자가 무한히 호출되는 형태 입니다.
	// => 복사 생성자는 call by value 로 만들수 없습니다.
	// Point( Point pt ) {}

	// 2. call by reference
	// => 컴파일 에러는 아님. 
	// => lvalue 만 받을수 있고, rvalue 를 받을수 없다.
	// => 값 타입으로 반환하는 함수의 결과를 받을수 없다.
	//    "Point ret = foo()" 가 에러!!
	// Point(Point& pt) {}

	// 방법 3. const lvalue reference
	// => lvalue 와 rvalue 를 모두 받을수있다.
	// => 컴파일러가 생성하는 복사 생성자가 이 모양.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
int main()
{
	Point p1;		// 1번 생성자
	Point p2(1, 2); // 2번 생성자

	Point p3( p2 );	// 복사 생성자 사용			

	Point p4 = foo(); // Point p4( foo() );
}




