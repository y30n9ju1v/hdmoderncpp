// 6_�����������ø�1 - 1

// "���ڰ� �Ѱ��� �Լ��� ����"�ϴ� ���ø�
template<typename T> void foo(T arg)
{
}

// ���� ���� �Լ� ���ø�
// => ... ��ġ �� �˾� �μ���.
// => ������ ������ N ���� �Լ��� �����Ҽ� �ִ� ���ø�
// => godbolt.org ���� Ȯ���� ������..( �� ����Ʈ �� Ȱ���ϼ��� )
template<typename ... Types> void goo(Types ... args)
{
}

int main()
{
	foo(1);		// foo(int)		����
	foo(3.4);	// foo(double)  ����

	goo(1);		// goo(int) ����
	goo(3.4);	// goo(double) ����
		
	goo(1, 3.4, "aaa"); // goo(int, double, const char*) ����
						// Types : int, double, const char*
						// args  : 1,   3.4,    "aaa"
}


