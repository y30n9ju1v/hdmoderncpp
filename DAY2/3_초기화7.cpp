
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 핵심 : Point 타입은 디폴트 생성자가 없습니다.

class Rect
{
	Point pt; // ?
public:
	// 사용자 코드	// 컴파일러가 변경한 코드
//	Rect() {}		// Rect() : pt() {}  
					// => Point의 디폴트 생성자가 없으므로 에러

	// C++98 시절 해결책 : 멤버 데이타의 생성자를 명시적으로 
	//					 호출하는 코드를 제공
	Rect() : pt(0, 0) {}
};

// C++11 해결책
class Rect
{
	Point pt{ 0, 0 }; // ok
	Point pt(0, 0);   // 주의!! ()는 안됩니다.
public:
}

int main()
{
	Rect r1;
}

