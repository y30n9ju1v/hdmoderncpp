// std::move()소개
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }
	// 복사 생성자 
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}
	/*
	// 이동 생성자(move constructor). rvalue를 위한 복사 생성자 
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
	*/
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;		// c1 은 lvalue. 복사
			
	Cat c3 = foo();		// 임시객체 rvalue. 이동

	Cat c4 = static_cast<Cat&&>(c2);
						// c2에 대해서도 복사가 아닌 이동을 해달라는 것

	Cat c5 = std::move(c3); // 이 표준 함수가 위와 같은 캐스팅을 수행
							// 합니다.

	// 주의 : std::move 자체가 자원을 이동하는 것 아닙니다.
	// 1. 단지 lvalue 객체를 "rvalue로 변환" 하는 작업만 합니다
	// 2. Cat 타입안에 move 생성자에서 실제 자원이 이동 됩니다.


	
	// move 생성자가 없는데. std::move() 를 사용했다면
	// 1. move 생성자가 있다면 move 생성자 호출. 자원의 이동!
	// 2. move 생성자가 없다면 copy 생성자 호출. 자원의 복사!

	// 즉, move 를 지원하지 않은 타입도, std::move() 사용가능합니다.
	// => 단, 성능 향상은 없습니다.
	Cat c6 = std::move(c4);
}




