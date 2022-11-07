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
							// => foo �� ���̻� override �ȵ�
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

// Ŭ���� �̸� �ڿ� final �ǹ� : ��� Ŭ������ ���ɼ� ����.
class Derived2 final : public Derived
{
public:
	virtual void foo()      override {} // error
	virtual void goo(int a) override {}
};

class Derived3 : public Derived2 // error. final Ŭ����
{
};

int main()
{
}