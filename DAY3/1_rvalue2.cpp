// �ٽ� : rvalue, lvalue �� ������ 
//       ����(��ü)�� �ο��Ǵ� ������ �ƴ�
// 
//       ǥ����(expression) �� �ο� �Ǵ� ����
// 
// expression : �Ѱ��� ���� ��Ÿ���� �ڵ� ����

int main()
{
	int n = 0;

	n = 10;		// ok.  "n" �̶�� �ڵ�� lvalue

	n + 1 = 10; // error. "n+1" �̶�� �ڵ�(ǥ����)�� rvalue

	(n = 20) = 10; // ok. "(n=20)" �̶�� ǥ������ lvalue

	++n = 10;		// ok

	n++ = 10;		// error. "n++" �� rvalue

	static_cast<int>(n) = 10;	// error. �� ĳ������ rvalue
	static_cast<int&>(n) = 10;	// ok.    ���� ĳ������ lvalue
}