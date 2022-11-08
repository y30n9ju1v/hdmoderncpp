// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "1 int" << std::endl;	}
	Point(int, int) { std::cout << "2 int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "3 initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	// Point(int) 생성자 호출
	Point p2(1, 2);	// Point(int, int) 생성자 호출

	Point p3( { 1,2 } ); // Point(initializer_list) 생성자 호출

	Point p4{ 1,2 };// 1. Point(initializer_list) 가 있으면 사용
					// 2. 1이 없다면 Point(int, int) 사용

//	Point p5(1, 2, 3); // error. Point(int, int,int) 는 없다

	Point p6{ 1, 2, 3 }; // ok.. Point(initializer_list) 사용
	Point p7 = { 1,2,3 };// ok.. Point(initializer_list) 사용

	// 결론 : 생성자 인자로 "initializer_list" 를 사용하면
	//       => 중괄호 초기화를 사용해서 인자 전달시 몇개라도 보낼수 있습니다.

	// C++11 이후 STL 사용시 아래 처럼 사용 가능한 원리
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };
				// vector(std::initializer_list<T>) 생성자 사용

	// std::initializer_list<T> 는 가벼운 타입입니다.
	// call by value 로 사용하면 됩니다.
}


