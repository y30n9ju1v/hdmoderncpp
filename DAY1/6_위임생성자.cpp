#include <iostream>
// 6_위임생성자 - 24page
class Point
{
public:
	int x, y;
public:
	// C++11 부터는 생성자에서 다른 생성자 호출 가능합니다.
	// => "위임 생성자" 라고 하고
	// => "초기화 리스트 문법" 으로 해야 합니다.
	Point() : Point(0, 0)
	{
//		Point(0, 0);	// 하나의 생성자에서 다른 생성자 호출 ?
						// => 다른 생성자를 호출하는 것이 아니라
						// => 임시객체를 만드는 표기법입니다.(내일)

		// 아래 처럼 하면 안되나요 ? => "placement new" 사용
		new(this) Point(0, 0);  // 에러는 아니지만
							// 절대 사용하지 마세요
							// "기반 클래스 생성자호출문제가있습니다."
	}
	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

