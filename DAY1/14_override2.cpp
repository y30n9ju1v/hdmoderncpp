#include <iostream>

template<typename T> class Base
{
public:
	virtual void foo(const T a)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// 가상함수 재정의시 override 붙이지 말고 해보세요.

};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나오게 해보세요.
}