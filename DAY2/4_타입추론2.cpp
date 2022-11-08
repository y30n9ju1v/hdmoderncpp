#include <iostream>

// ��Ģ 1. ���ø� �Ķ���Ͱ� "�� Ÿ��(T a)" �϶�
// => �Լ����ڰ� ������ const, volatile, reference �� �����ϰ�
//    Ÿ���� ����

template<typename T> void foo(T a)
{
//	a = 100;
	// T�� Ÿ���� Ȯ�� �ϴ� ��� 1. C++ RTTI ��� ���
	// => reference, volatile ��ȣ�� ǥ�õ��� �ʽ��ϴ�.
	// => ��Ȯ���� �ʽ��ϴ�. ������� ������
	// std::cout << typeid(T).name() << std::endl;

	// �Լ� �̸��� ����ϴ� ��ũ�θ� ����ϼ���
	// VC++ : __FUNCSIG__
	// g++  : __PRETTY_FUNCTION__
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	// ����ڰ� Ÿ�� ����, �����Ϸ��� Ÿ�� �߷����� ����.
	// => ����ڰ� ������ Ÿ�� ���
	foo<int>(3);

	// Ÿ���� �������� ������ �Լ� ���ڷ� Ÿ�� �߷�
	foo(10);	// T=int
	foo(3.4);	// T=double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n); // T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int

	// �����͵� �ᱹ�� ���Դϴ�.(�ּҰ�)
	// => ���� ! ������ const �� ���� �˴ϴ�.
	// => �Ʒ� �ڵ忡�� "s1" �� const �ƴմϴ�. s1�� ����Ű�� ���� const
	const char* s1 = "hello";
	foo(s1); // T = const char*

	const char* const s2 = "hello";
	foo(s2); // T = const char*
			 //     char const* �� ����
			 //     char* const �� ǥ���� �ٸ� Ÿ��(������ ��ü�� const)
}