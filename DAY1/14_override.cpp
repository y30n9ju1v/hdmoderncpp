// 14_override  - 44 page

class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};
class Derived : public Base
{
public:
	// 가상 함수 재정의시 실수(오타)
	// => 에러가 아니라, 새로운 가상함수로 인식하게 됩니다.
	//    아래 코드는 모두 에러가 아닙니다.
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};

class Derived2 : public Base
{
public:
	// C++11 부터, 가상함수를 재정의시 "override" 를 붙이는 것이 
	// 안전합니다.
	// => 컴파일러에게 가상함수를 새로 만드는 것이 아니라
	//    재정의(override) 한다고 알려 주는 것
	virtual void fooo()        override {} // error
	virtual void goo(double a) override {} // error
	virtual void hoo() const   override  {}// error
};

int main()
{
}