#include <iostream>

// rule of 5, 3

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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	// 복사 생성자를 만들게 되는 타입은 대부분 대입연산자도
	// 만들어야 합니다.
	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;

		// 이름은 깊은 복사
		delete[] name; // 사용하던 자원 삭제
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}
	// 대입 연산자도 "move 버전"을 제공해야 합니다.
	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;
	
		delete[] name;
		name = c.name;	// move 버전은 얕은 복사후
		c.name = nullptr;// 원본 객체 자원포인터 reset

		return *this;
	}


};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// 복사 생성자 ( 초기화, 생성하면서 넣기)
	c2 = c1;		// 대입 연산자 ( 대입, 생성후 넣기)
					// c2.operator=(c1) 가 호출
					// 사용자가 만들지 않으면 컴파일러 제공
					// (얕은 복사!)

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




