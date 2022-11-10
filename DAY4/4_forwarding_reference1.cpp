// forwarding reference �̾߱�

template<typename T> class Test
{
public:
	// �ٽ� : �Ʒ� �Լ� ���ڴ� ���� "forwarding reference" �� �ƴմϴ�.
	// �Ʒ� �Լ��� "�Լ� ���ø�" �� �ƴ�
	//           "Ŭ���� ���ø�"�� "�Ϲ� ��� �Լ�" �Դϴ�.
	// Test<int> t; // ��ü ������ �̹� T �� Ÿ���� ����
	void foo(T&& arg)
	{
	}

	// forwarding reference �� �Ƿ��� 
	// �Լ�(�Ǵ� ��� �Լ�) ��ü�� ���ø� �̾�� �մϴ�.
	// => �Ʒ� �Լ� ���ڰ� forwarding reference �Դϴ�.
	template<typename U>
	void goo(U&& arg)   
	{

	}
};
int main()
{
	int n = 0;
	Test<int> t; // ��ü ������ �̹� T �� Ÿ���� ���� ( T=int)
				// ����, foo �Լ��� "foo(int&&)" �� �����Ǿ����ϴ�.
	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n);	// error
	t.foo(10);	// ok

	t.goo(n);  // ok
	t.goo(10); // ok
}
