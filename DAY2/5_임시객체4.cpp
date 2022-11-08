// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

/*
void f1(Point  pt) {}	// call by value : 복사본 객체 생성
void f2(Point& pt) {}	// call by reference : 복사본 생성 안됨.

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//=====================================================





Point pt(1, 2);

Point foo()  // return by value
{			 // 임시객체를 생성해서 반환.
	return pt; 
}
Point& goo() // return by reference
{
	return pt; // 임시객체가 아닌 pt 의 별명 반환
}


// 주의!! 지역변수는 절대로 참조 반환하면 안됩니다.
// 파괴되지 않은 객체(전역변수, 또는 멤버 데이타등)만 참조 반환해야 합니다
Point& hoo()
{
	Point p(1, 2);
	return p; // 버그. 그런데, 에러는 아니고, 경고 입니다.
}

int main()
{
	foo().x = 10; // error. 리턴용임시객체.x = 10 이므로 에러
				  // 임시객체는 등호의 왼쪽에 올수 없다.

	goo().x = 10; // ok. pt.x = 10 과 동일. 

// 	Point& ret = hoo();
//	hoo().x = 10; // 이렇게도 사용하면 안됩니다.(지역변수 반환이라면)
}





