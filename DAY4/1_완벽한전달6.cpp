#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // �ʿ� ���� ĳ���� �Դϴ�.
								// �־ ���� �ƴմϴ�.
								// �������ϵ� �����ϴ�.
								// ������ �ð��� ���� �˴ϴ�.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/
// �ٽ� : forwarding reference(T&&) �� ����ϸ� 
//       ��� Ÿ�Կ� ���ؼ� rvalue reference, lvalue reference �Լ���
//       �����Ҽ� �ִ�.
//		=> �׷���, �Լ� ���ø����� ������� ������ �����ؾ� �Ѵ�.

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	// �ٽ� 1. �Ʒ� ĳ������ ���� "rvalue ĳ����"�� �ƴմϴ�.
	//        chronometry(�Լ�, n)  : static_cast<int&>(arg)
	//        chronometry(�Լ�, 10) : static_cast<int&&>(arg)

	// ��, 
	// (���ڷ�) lvalue �� (�����ϸ�) lvalue �� ĳ�����ϰ�
	//         rvalue �� (�����ϸ�  �����鼭 lvalue ���� ���� ) 
	//								�ٽ� rvalue �� ĳ���� �մϴ�.
//	f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // �� �Լ��� �ϴ� ����
							// �� ĳ���� �Դϴ�.
							// "T&&" �� �ƴ϶� "T" �� �����ϸ�˴ϴ�.
}

int main()
{
	int n = 0;
	chronometry(goo, n);	// T=int&,  T&&=int& && => int&
							// �Լ� ��� : chronometry(F f, int& )
							// ĳ���� ���: static_cast<int&>(arg);

	chronometry(foo, 10);	// T=int,  T&&=int&&
							// �Լ� ��� : chronometry(F f, int&& )
							// ĳ���� ���: static_cast<int&&>(arg);
}
