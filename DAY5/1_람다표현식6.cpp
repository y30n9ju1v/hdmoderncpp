// 145 page
#include <iostream>
int main()
{
	// ����ǥ������ ��Ȯ�� ���
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 1. return ������ �Ѱ���� return Ÿ�� ���� �����մϴ�
	auto f2 = [](int a, int b) { return a + b; };


	// 2. return ������ 2���� ���� Ÿ���̸� ���� ����
	auto f2 = [](int a, int b) { if (a == 1) return a;  return b; };

	// 3. return ������ 2���ε�, �ٸ�  Ÿ���̸� ���� �Ҽ� �����ϴ�.
	// �Ʒ� �ڵ�� ����
	auto f3 = [](int a, double b) { if (a == 1) return a;  return b; };

}

