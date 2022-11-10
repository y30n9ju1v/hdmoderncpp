// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// �ٽ� : int Ÿ�� ���� �Ѱ��� �Ϻ��� �����Ϸ���
// 1. int&, int&& ������ �Լ��� ���� ����
// 2. rvalue reference(int&&) ������ "rvalue �� ĳ����"�ؼ� ����

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}


int main()
{
	hoo(10);
	chronometry(hoo, 10);
}
