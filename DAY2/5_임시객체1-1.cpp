// 5_임시객체1-1

// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// 객체를 만드는 2가지 방법
//	Point pt(1, 2); // named object
					// 이름이 있으므로 여러 문장에서 사용가능
					// 수명 : 자신을 선언한 블럭의 끝.

//	Point(1, 2);	// unnamed object
					// temporary (임시객체) 라고도 합니다.
					// 수명 : 자신을 생성한 "문장의 끝"

	// 아래 코드 결과 예측해 보세요.
	Point(1, 2), std::cout << "X" << std::endl; 

	std::cout << "-------" << std::endl;
}





