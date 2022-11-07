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
	// ���� �Լ� �����ǽ� �Ǽ�(��Ÿ)
	// => ������ �ƴ϶�, ���ο� �����Լ��� �ν��ϰ� �˴ϴ�.
	//    �Ʒ� �ڵ�� ��� ������ �ƴմϴ�.
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};

class Derived2 : public Base
{
public:
	// C++11 ����, �����Լ��� �����ǽ� "override" �� ���̴� ���� 
	// �����մϴ�.
	// => �����Ϸ����� �����Լ��� ���� ����� ���� �ƴ϶�
	//    ������(override) �Ѵٰ� �˷� �ִ� ��
	virtual void fooo()        override {} // error
	virtual void goo(double a) override {} // error
	virtual void hoo() const   override  {}// error
};

int main()
{
}