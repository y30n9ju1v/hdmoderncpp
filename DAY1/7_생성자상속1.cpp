// 7_생성자상속1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// 생성자는 기본적으로 상속되지 않습니다.

	// C++11 부터는 아래 처럼 사용하면 생성자를 상속 받을수 있습니다.
	using Base::Base; // "클래스이름::멤버함수이름"

	// 위 문법이 없던 시절은 아래처럼 만들어서 사용했습니다.
//	Derived()	   : Base() {}
//	Derived(int n) : Base(n) {}
};

int main()
{
	// 아래 2줄을 생각해 보세요
	Derived d1;
	Derived d2(5);
}
