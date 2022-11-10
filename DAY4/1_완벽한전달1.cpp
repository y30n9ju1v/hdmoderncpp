// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding         : �Լ� �� ���޹��� ���ڸ� �ٸ� �Լ��� ������ ��
// perfect forwarding : ���� ���� ������ ��� ��ȭ�� ����
//						�״�� �����ϴ� ��

// Ư�� �Լ��� ����ð��� �����ϴ� �Լ��� ����� ���ô�.
template<typename F, typename ARG>
void chronometry(F f, ARG arg)
{
			// �Լ� ȣ������ �ð� ���
	f(arg);	// �Լ� ȣ��
			// �Լ� ���࿡ �ҿ�� �ð� ���
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
