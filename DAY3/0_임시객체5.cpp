#include <iostream>
// 85 page
struct Base
{
	int value = 10; 
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;	// 20
	std::cout << static_cast<Base>(d).value << std::endl;	// 10 
	std::cout << static_cast<Base&>(d).value << std::endl;	// 10

	static_cast<Base>(d).value = 20;	// error. 임시객체는
										//   lvalue 가 될수 없다.
	static_cast<Base&>(d).value = 20;	// ok

	// 값 캐스팅은 "임시객체를 생성" 하는 표기법 입니다.
}

