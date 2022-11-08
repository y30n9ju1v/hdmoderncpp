// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};
int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 }; // copy   initialization
	int n3;			// default initialization
	int n4{};		// value initialization	
					// => 디폴트 값인 0으로 초기화

	std::cout << n4 << std::endl; // 0

	Point pt{};		// 모든 멤버를 0으로
					// 단, 사용자가 제공하는 생성자가 없을때
					// "= default" 인 경우는 0으로!

	std::cout << pt.x << std::endl;

	int arr[5] = {};
	std::cout << arr[3] << std::endl;
}


