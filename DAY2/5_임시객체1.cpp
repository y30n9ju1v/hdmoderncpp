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





//	Point pt(1, 2); 
//	std::cout << "-------" << std::endl;
}





