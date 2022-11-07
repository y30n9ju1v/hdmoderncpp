// �Ϲ� �Լ� : ����ð����� ����ɼ� �ֽ��ϴ�.
int add1(int a, int b) { return a + b; }

// constexpr �Լ�
// => ����ð��� ����ɼ��� �ְ�, 
// => ������ �ð��� ����ɼ��� �ֽ��ϴ�.
constexpr int add2(int a, int b) { return a + b; }

// consteval �Լ� (C++20)
// => ������ �ð����� ����ɼ� �ֽ��ϴ�.
consteval int add3(int a, int b) { return a + b; }

int main()
{
	int x = 1, y = 2;

	add3(1, 2); // ok. ������ �ð��� ���� ����
	add3(x, y); // error
}