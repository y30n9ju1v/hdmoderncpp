// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
//-------------------------------
void f1(int  arg) {}
void f2(Point pt) {}

int main()
{
	// f1에 3을 보내고 싶다.
	// 방법 1. 변수를 만들어서 전달
	int n = 3;
	f1(n);

	// 방법 2. 인자로 전달할 "3"만 필요 하면 literal 형태로 전달하면된다.
	f1(3);

	//================================
	// f2 에 1, 2라는 점을 보내고 싶다.
	// 방법 1. 객체를 생성해서 전달
	Point pt(1, 2);

	f2(pt);

	// 방법 2. Point 타입의 literal 전달
	f2( Point(1, 2) );	// 인자 전달용으로만 사용하는 객체 생성
						// 임시 객체 라고도 하고(temporary)
						// "unnamed object"
						// "user define type 의 literal" 
						// 이라고도 합니다.


//	Point pt(1, 2); 
//	std::cout << "-------" << std::endl;
}





