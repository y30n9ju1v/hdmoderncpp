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
	virtual void foo()      override final {} 
							// => foo 는 더이상 override 안됨
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

// 클래스 이름 뒤에 final 의미 : 기반 클래스로 사용될수 없다.
class Derived2 final : public Derived
{
public:
	virtual void foo()      override {} // error
	virtual void goo(int a) override {}
};

class Derived3 : public Derived2 // error. final 클래스
{
};

int main()
{
}