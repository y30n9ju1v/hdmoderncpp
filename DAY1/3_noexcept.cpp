// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept �� �ǹ�

// 1. �Լ��� ���ܰ� ������ �����Ϸ����� �˸��� ��
void foo() {}		// ������ ���ɼ��� �ִٴ� �ǹ�!

void goo() noexcept // ���ܰ� �߻����� �ʴ´ٰ� �����Ϸ�����
{					// �˷� �ִ� ��
}
void hoo()
{
	if (1) // ����
		throw std::bad_alloc();
}
int main()
{
	// noexcept �ǹ� 2. �Լ��� ���ܰ� �ִ��� ����
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());
	bool b3 = noexcept(hoo());

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
}




