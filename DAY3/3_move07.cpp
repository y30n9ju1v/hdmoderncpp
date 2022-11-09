// move 계열함수 에서는 모든 멤버를 move로 옮겨라!
#include <iostream>
#include <string>

// 클래스가 사용하는 자원은

// 1. 클래스 자체가 관리할수 있습니다.(char* name)
// 2. 클래스의 멤버에 의해 관리될수 있습니다.(string addr)








class Cat
{
	char* name;
	int   age;
	std::string addr;
public:
	Cat(const char* n, int a, const std::string& add) 
		: age(a), addr(add)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// 복사 생성자
	Cat(const Cat& c) : age(c.age), addr(c.addr)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}








	// 핵심 : move 생성자에서는 모든 멤버를 move로 옮기세요!
	// addr(c.addr) : string 의 복사 생성자 호출 - 문자열의 복사 입니다
	// addr(std::move(c.addr)) : string 의 move 생성자 호출

	// 단, primitive 타입의 경우 "std::move" 가 있어도 되고 없어도 됩니다.
	Cat(Cat&& c) : age(c.age), name(c.name), addr(std::move(c.addr))
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;
		addr = c.addr;

		delete[] name; 
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;
		addr = std::move(c.addr); // !!! 핵심 move 대입에서는
								// 모든 멤버를 move 로 대입!

		delete[] name;
		name = c.name;	
		c.name = nullptr;

		return *this;
	}


};
int main()
{

}





