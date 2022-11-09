struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};



// 방법 1. call by value
// => lvalue, rvalue 모두 받을수 있지만
// => 복사본이 생성된다.
// void foo(Point pt) {}


// 방법 2. call by reference
// => 복사본은 생성되지 않지만
// => lvalue 만 받을수 있다, rvalue 는 받을수 없다.
// void foo(Point& pt) {}


// 방법 3. call by const lvalue reference
// => 복사본 없고,
// => lvalue, rvalue 모두 가능하다.
// => 그런데, const 속성 추가됨. std::move(pt) 같은 작업은 안됨. 읽기만 가능
// void foo(const Point& pt) {}

//========== C++98은 여기까지만!!=========================

// 방법 4. 2개의 함수 - C++11 이후
// => 복사본 없고, const 도 추가 안되고, lvalue/rvalue 모두 가능
// void foo(Point&  pt) {}
// void foo(Point&& pt) {}


// 방법 5. forwarding reference 사용
// => 방법4의 2개 함수가 하는일이 유사(동일)하고
// => Point 뿐 아니라 모든 타입에 필요 하면
// => forwarding reference 를 사용하면 자동 생성할수 있다.

template<typename T> void foo(T&& pt) {}


int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
