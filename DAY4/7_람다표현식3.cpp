#include <iostream>

// auto �� ���� ǥ����
int main()
{
	// �ٽ� 1. ����ǥ������ ���� ����� �ӽð�ü �Դϴ�.
	// �ٽ� 2. ���� ǥ������ auto ������ ��Ƽ� �Լ� ó�� ��밡��.

	auto f = [](int a, int b) { return a + b; };
			// class xxx{ operator()() }; xxx();

	int n1 = f(1, 2);
	int n2 = f.operator()(1, 2); // �̷��Ե� �����մϴ�.


	// �ٽ� 3. ������ ������ ��� ������!

	auto  a1 = [](int a, int b) { return a + b; };
	auto& a2 = [](int a, int b) { return a + b; };

	const auto& a3 = [](int a, int b) { return a + b; };

	auto&& a4 = [](int a, int b) { return a + b; };	

}

