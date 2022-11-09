#include <iostream>
#include <string>

// 자동 생성 규칙.
// 규칙1. 사용자가 복사계열과 move 계열 함수를 모두 제공하지 않으면
// => 컴파일러가 모두 제공한다.
// => 복사 계열에서는 "모든 멤버를 복사" 해주고
// => 이동 계열에서는 "모든 멤버를 이동" 해준다.

// 규칙 2. 사용자가 복사 계열만 제공하면
// => 컴파일러는 move 계열을 자동생성하지 않는다.
// => std::move() 사용시 사용자가 만든 복사계열 함수 호출.

// => "=default" 를 사용하면 컴파일러에게 move 계열 함수를 만들어달라고
//    요청할수 있다.

// 규칙 3. 사용자가 move 계열만 제공한 경우
// => 컴파일러는 복사 계열(생성자, 복사 대입)를 삭제("=delete") 합니다.
// => 복사 생성자가 필요한 코드는 모두 에러!

// => 복사 생성자를 직접 만들거나 또는 "=default"로 요청할수도 있습니다.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}


//	Object(const Object& obj) : name(obj.name) {std::cout << "user define copy" << std::endl;}
//	Object(Object&& obj) = default;
//	Object& operator=(const Object&) = default;
//	Object& operator=(Object&&) = default;

	// move 생성자만 제공한 경우
	Object(Object&& obj) : name(std::move(obj.name)) {}
};

int main() 
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}