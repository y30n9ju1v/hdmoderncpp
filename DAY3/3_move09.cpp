// Rule Of 0
#include <iostream>
#include <string>

// rule of 0 : 복사와 move 모두 만들지 않은 것이 가장 좋다.!

// => 자원을 직접 관리하지 말고, 자원 관리 클래스를 사용해라.

// const char* => std::string
// int*        => std::vector 또는 스마트 포인터

class Cat
{
	std::string name;
	int   age;
	std::string addr;
public:
	Cat(const std::string& n, int a, const std::string& add)
		: name(n), age(a), addr(add)
	{
	}
};

int main()
{

}






