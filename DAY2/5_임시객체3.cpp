// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//================================================
// 임시객체와 함수 인자 - 81 page

// 함수 인자로
// const Point& : 인자로 전달된 객체는 읽기만 하겠다는 것(in parameter)
// Point&       : 인자로 전달된 객체를 수정하겠다는 의도(out paremeter)
//										 또는 in/out parameter
void draw_point(const Point& pt) {}
void init_point(Point& pt) { pt.x = 0; }


int main()
{
//	Point pt(1, 2);
//	draw_point(pt);

	// 핵심 1. 함수 인자로만 사용할 객체가 필요 하면
	//        "임시객체" 형태로 전달하는 것이 좋다
	draw_point( Point(1, 2) );

	// 핵심 2. 아래 코드가 되는게 좋은지 안되는게 좋은지 생각해 보세요
	draw_point(Point(1, 2)); // 되야 한다.
							 // 그래서 const & 로 임시객체를 받을수 있다
	
	init_point(Point(1, 2)); // 안되는 게 논리적으로 맞다
							 // 그래서 non-const & 로는 임시객체를
							 // 받을수 없다
							 // error 


	std::cout << "-----" << std::endl;
}






