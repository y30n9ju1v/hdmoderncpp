// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}
	// C++17 �� ���ο� ���
	// => �ʱ�ȭ ������ ������ if ��
	// => if ( init; condition) 

	if (int ret2 = foo(); ret2 == 0)
	{
	} // <= ret2 �ı�. 

	// switch �� �����մϴ�.
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}

	// while �� �ɱ�� ?
	// => �ȵ˴ϴ�.
	// => �ʿ�����ϴ�. for ������ϸ� �˴ϴ�.
	/*
	while (int cnt = 0; cnt < 10) 
	{
		++cnt;
	}
	*/
}




// github.com/codenuri/hdmoderncpp   ���� DAY2.zip �����ø� �˴ϴ�.
// VC ���� ���� ���� ������ �ּ���.

