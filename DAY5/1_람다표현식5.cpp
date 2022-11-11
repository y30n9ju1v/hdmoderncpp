// 143 
#include <functional>

int main()
{
	// ����ǥ������ ��� ���
	// 1. auto ������ ���
	auto f1 = [](int a, int b) { return a + b; };

	// 2. �Լ� ������
	int(*f2)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{ operator()()}; xxx();

	// 3. std::function ���� ������ �ֽ��ϴ�.
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// ���� f1, f2, f3 �� �Ϲ� �Լ� ó�� ��밡���մϴ�.
	f1(1, 2);
	f2(1, 2);
	f3(1, 2);

	// ������ : auto ������ �ٸ� ���ٸ� ������ �����ϴ�.
	f1 = [](int a, int b) { return a + b; }; // error

	// f2, f3 �� �����Ϸ��� ������ ���� Ÿ���� �ƴ�
	// �Լ� ������, std::function Ÿ���� �����̹Ƿ� ���氡���մϴ�
	f2 = [](int a, int b) { return a + b; }; // ok
	f3 = [](int a, int b) { return a + b; }; // ok

	f1(1, 2); // �ζ��� ġȯ �˴ϴ�.
	f2(1, 2); // �ζ��� ġȯ �ȵ˴ϴ�. 
			  // �ζ��� �Լ� �� �Լ� �����Ϳ� ������ ġȯ�ɼ� ����.
	f3(1, 2); // ġȯ �ȵ�
}