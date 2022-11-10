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
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(goo, n);	// T=?,  T&&=?
							// �Լ� ��� : chronometry(F f, ? )
							// ĳ���� ���: static_cast<?>(arg);

	chronometry(foo, 10);	// T=?,  T&&=?
							// �Լ� ��� : chronometry(F f, ? )
							// ĳ���� ���: static_cast<?>(arg);
}
