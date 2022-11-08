// decltype ��Ģ 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// ��Ģ 2. () �ȿ� "�ɺ��� �̸��� �����ڵ��� ������ ǥ������ ������"
	// => ()���� ǥ������ lvalue �� �ɼ� ������ ����
	//    ��ȣ�� ���ʿ� �ü� ������(lvalue �ƴϸ�) �� Ÿ��
	decltype(p)		d1; // int*,  ��Ģ 1
	decltype(*p)	d2; // int&, *p = 0 ����.  �ʱⰪ �����Ƿ� ����
	decltype(x[0])	d3; // int&, x[0] = 0 ����. �ʱⰪ ������ ����

	decltype(n) d;	// n = 0 �̹Ƿ� lvalue �� �ɼ� ������
					// �̸��� �����Ƿ� ��Ģ 1
					// int
	
	decltype((n)) dd; // int&,  ��Ģ 2


	decltype(n + n) d4; // int,  n+n = 0 �� �ȵ�. 

	n = 3;
	decltype(++n)   d5; // int&,  ++n = 10 �� ������ �ƴմϴ�.
						
						
	decltype(n++)   d6; // int, n++ = 10 �� ���� �Դϴ�.


	int y[3] = { 1,2,3 };

	decltype(y[0]) k1; // int&
	auto k2 = y[0];	   // int, y[0] �� ����Ÿ���ε�..
						//     auto �� �캯�� ������ ������ �����ϹǷ�

}

