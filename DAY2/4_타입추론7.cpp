// decltype Ÿ�� �߷� - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// ����!
	auto a = r; // int a = r;
				// auto �� �캯�� ������ ������ ����

	// ��Ģ 1. () �ȿ� �ɺ��� �̸��� �ִ� ���
	// => �ɺ��� ������ ���� ������ Ÿ������ ����
	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;			�ʱⰪ �����Ƿ� error
	decltype(c) d3; // const int d3;	�ʱⰪ �����Ƿ� error
	decltype(p) d4; // int* d4;
}