#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&


	int&& r2 = 10;	// �� �ڵ忡��
					// "10" �� rvalue ������
					// r2 �� lvalue �Դϴ�.

	foo(r2);	// int&

	// Ÿ�԰� value �Ӽ��� �� �����ϼ���
	//			Ÿ��			value �Ӽ�
	// n		int			lvalue
	// n+1		int			rvalue
	// 10		int			rvalue
	// r1		int&		lvalue
	// r2		int&&		lvalue

	foo(r2); // int&
	foo(static_cast<int&&>(r2)); // int&&
		// => r2 �� int&& Ÿ���̹Ƿ� �ᱹ ���� Ÿ�� ĳ���� �ƴѰ��� ?
		// => �� ĳ������ Ÿ�� ĳ������ �ƴմϴ�.
		// => value �Ӽ��� �����ϴ� ĳ���� �Դϴ�.
		//    lvalue => rvalue(��Ȯ���� xvalue) �� ĳ�����ϴ� ���Դϴ�.
		// cppreference.com ���� static_cast ã�ƺ�����
}
void f1(int&) {}	// "int&" Ÿ���� �ްڴٴ� ���� �ƴ϶�
					// lvalue �� �ްڴٴ� ��
void f1(int&&) {}	// "int&&" Ÿ���� �ްڴٴ� ���� �ƴ϶�
					// rvalue �� �ްڴٴ� ��





