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

	//------------------

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);

		std::cout << "copy" << std::endl;
	}
	// 임시객체일때를 위한 
	// 복사생성자를 별도로 제공합니다.
	Cat(Cat&& c) : name(c.name), age(c.age) // 모든 멤버를 얕은복사
	{
		// 임시객체가 파괴될때 자원을 지우지 못하게 하기위해
		// 자원 포인터를 0 으로
		// => 이 코드를 하려면 임시객체(rvalue) 도 상태 변경이 가능
		//    해야 합니다.
		//    "상수성(const)없이 임시객체를 가리킬수 있어야 합니다.
		c.name = nullptr;

		std::cout << "move" << std::endl;
	}
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1; // copy

	Cat c3 = foo(); // move 이순간의 메모리 그림을 생각해 봅시다.
}