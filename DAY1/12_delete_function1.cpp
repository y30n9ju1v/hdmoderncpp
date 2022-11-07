
// special member function
// => 사용자가 만들지 않으면 컴파일러가 만드는 멤버 함수들. 6개
// C++98 : 생성자, 소멸자, 복사 생성자, 대입 연산자
// C++11 : move 생성자, move 대입 연산자

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 컴파일러가 복사 생성자를 만들지 못하게 하는 예전 기술
	// => 복사 생성자를 private 영역에 선언만 합니다.
	/*
private:
	Point(const Point&);
	*/

	// 그런데, 위 기술은 "문법이 아닌 테크닉"입니다.
	// C++11 부터는 "컴파일러에게 특정 함수를 만들지 말라(지워달라)"
	// 는 문법이 도입
	Point(const Point&) = delete; // 함수 삭제
	Point& operator(const Point&) = delete; // 대입연산자 삭제
};

int main()
{
	Point p1;
	Point p2(1, 2);
//	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // 컴파일러가 만들어주는 복사 생성자 사용
}