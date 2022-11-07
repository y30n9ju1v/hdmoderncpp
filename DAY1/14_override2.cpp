#include <iostream>

template<typename T> class Base
{
public:
	// �Ʒ� �ڵ�� "a" �� const �Դϴ�.
	//virtual void foo(const T a) // �� �ڵ��
	virtual void foo(T const  a)  // �� �ڵ�� �����մϴ�.
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// �����Լ� �����ǽ� override ������ ���� �غ�����.
	// �Ʒ� �ڵ�� "a" �� const �� �ƴմϴ�.
	// "a �� ����Ű�� ��"�� const �Դϴ�.
	//virtual void foo(const int* a) 

	virtual void foo( int* const a)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" ������ �غ�����.
}

// ���ڵ尡 ������ ���� �Ʒ� 3�� C���� ã�� ������
int n = 0;
const int* p1 = &n;
int const* p2 = &n;
int* const p3 = &n;