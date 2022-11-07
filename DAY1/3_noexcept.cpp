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
	bool b1 = noexcept(foo()); // false
	bool b2 = noexcept(goo()); // true
	bool b3 = noexcept(hoo()); // false
	 
	std::cout << b1 << std::endl; // 0
	std::cout << b2 << std::endl; // 1
	std::cout << b3 << std::endl; // 0
}
// �Լ��� ���ܰ� ���ٸ� �ǵ��� "noexcept" �� ���̼���
// 1. �����Ϸ� ����ȭ�� �� ������ �˴ϴ�.
// 2. noexcept �� �� �ʿ��� ��찡 �ֽ��ϴ�. - move, swap, �Ҹ���
//										���� ���ϴ�.
							// ��, �Ҹ��ڴ� noexcept�� ������ �ʾƵ�
							// ����Ʈ�� noexcept �Դϴ�.




