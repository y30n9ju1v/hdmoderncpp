// 9_enum - 32 page

enum DAYOFWEEK { sum = 0, mon = 1};

// �Լ� ���ڷ� ������ �ް� �ʹ�.
void foo(int dayofaweek) {}

int main()
{
	foo(0); // 0 : �Ͽ���, 1 : ������ .... 
			// => �������� ���� �ʴ�.

	foo(DAYOFWEEK::mon); // �̷��� �ص� �ǰ�
	foo(mon);	// �̷��� �ص� �˴ϴ�.
				// "unscoped enum" 
				// �̸� �浹�� ���ɼ��� �ִ�. 
				// ���� ������ ���ο� enum �� ������!
	int mon = 100;
	foo(mon);	// ???? ���� ? enum ? �������� ?
				// => �������� ���
}





