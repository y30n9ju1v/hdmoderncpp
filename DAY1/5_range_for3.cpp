#include <iostream>
#include <vector>

// 사용자 정의 타입을 새로운 for 문(range-for) 에 넣으려면
// begin()/end() 를 멤버 함수 또는 일반함수로 제공하면 됩니다.

struct Point3D
{
	int x, y, z;

//	int* begin() { return &x; }
//	int* end()   { return &z + 1; } // 마지막 다음 요소를
									// 가리키는 반복자(주소)
};
int* begin(Point3D& p) { return &(p.x); }
int* end(Point3D& p)   { return &(p.z) + 1; }


int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl; 
	//=================
//	auto first = std::begin(p); // 이 가능해야 합니다
}















