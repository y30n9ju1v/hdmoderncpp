// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
//	Test::data  * p;	// 0 * 0.  ��, * �� ���ϱ� ������(���׿�����) 
//	Test::DWORD * p;	// int* p  ��, * �� ������ ���� ����

	// �ٽ� 1. "Ŭ���� �̸�::�̸�" ���� ǥ���Ҷ� "�̸�"�� �ǹ̴�
	// "��"  �Ǵ�			   : enum ���, static ��� ��
	// "Ÿ��" �ϼ� �ֽ��ϴ�.  : typedef, using ��

	// dependent name(�����̸�)
	// => ���ø� ���� T�� �����ؼ� ������ �̸�
	// => �����Ϸ��� �׻� "��"���� �ؼ� �մϴ�.

	T::data * p;		// ok
//	T::DWORD * p2;		// error

	typename T::DWORD* p2; // ok

	// �ٽ� 2. dependent name �� type �� ���� 
	//		�ݵ�� �տ� "typename" �� �ٿ��� �մϴ�.
	// => C++98 ���� ����
}



int main()
{
	Test t;
	foo(t);
}



