// 1_초기화11 - 65 page..
// aggregate initialization

// aggregate 타입이란 ?
// => 생성자가 없어도 {}로 초기화 가능한 타입
// => 구조체, 배열, union 
// => 아래 Point 에 "Point()" 생성자가 있으면 aggregate 가 아닙니다.
//    Point pt = {1,2} 초기화 안됩니다.

struct Point
{
	int x, y;

	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2
};

int main()
{
	Point p1;			// 1 번 생성자
	Point p2 = { 1, 2 };// 2 번 생성자
}