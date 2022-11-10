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
	// => ���� ǥ������ "�ӽð�ü(rvalue)" �Դϴ�. 

	auto  a1 = [](int a, int b) { return a + b; };	// ok

	auto& a2 = [](int a, int b) { return a + b; };	// error

	const auto& a3 = [](int a, int b) { return a + b; }; // ok

	auto&& a4 = [](int a, int b) { return a + b; };	// ok
	// forwarding reference !!

	// �� 4���� ���� ���� �ڵ�� "a1" �Դϴ�.
	CompilerGenratedName a1 = CompilerGenratedName(); // �ε�
				// ����(move) ������ ����ȭ �� ���ؼ� �Ʒ��ڵ� ó���˴ϴ�.

	CompilerGenratedName a1; 
}

