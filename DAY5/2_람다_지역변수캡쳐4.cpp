// 149
int main()
{
	int v1 = 0, v2 = 0;

	// 
	auto f1 = [v1, &v2](int a) { ... }; // v1�� ��, v2�� ����
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... }; // ��� ���������� "�� ĸ��"
	auto f4 = [&](int a) { ... }; // ��� ���������� "���� ĸ��"

	auto f5 = [=, &v2](int a) { ... }; // v2�� ����, �������� "��"
	auto f6 = [&,  v2](int a) { ... }; // v2�� ��,   �������� "����"
	auto f7 = [&, &v2](int a) { ... }; // error. 
										// ����Ʈ���� �ٸ� ��츸 ǥ��

	// ���� �̸� ����
	// int  x = v1;
	// int& y = v2;
	auto f8 = [x = v1, &y = v2](int a) { x, y };

	// int x = std::move(v1)
	auto f9 = [x = std::move(v1)](int a) { x };
}




