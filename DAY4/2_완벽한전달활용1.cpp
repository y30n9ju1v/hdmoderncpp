// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 객체를 생성후에 넣기
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. 임시객체를 사용해서 넣기
//	v.push_back(Point(1, 2));

	// 3. {} 로 초기화 표기법으로 전달
	// => 2와 동일 {1,2}를 가지고 임시객체 생성하는 원리
//	v.push_back({ 1,2 });


	// 4. 핵심!!!!!
	// => 객체를 전달하지 말고 객체를 만들기 위한 생성자 인자를 전달하자!

	v.emplace_back(1, 2);
			// 이 함수 안에서 
			// "new Point(1,2)" 처럼 객체를만들어서
			// 버퍼에 보관
			
			// emplace_back 은 자신이 전달 받은 모든 인자를
			// Point 의 생성자로 "완벽한 전달" 해야 합니다.



	std::cout << "-----" << std::endl;
}


