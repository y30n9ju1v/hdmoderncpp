#include <iostream>

// 90 page

// �Ʒ� ó�� �Լ� �����ε� �����մϴ�.
void foo(int& a)       { std::cout << "1 int&" << std::endl; }
void foo(const int& a) { std::cout << "2 const int&" << std::endl; }
void foo(int&& a)      { std::cout << "3 int&&" << std::endl; }

int main()
{
	int n = 10;

	foo(n);		// lvalue �̹Ƿ� 1, 2 ��� �����ѵ�
				// (1)�� ���õ˴ϴ�. (1)�� ������ (2) ȣ��

	foo(10);	// 10 �� rvalue �̹Ƿ�, 2, 3 ��� �����ѵ�
				// (3)�� ���õ˴ϴ�. (3)�� ������ (2) ȣ��

}







