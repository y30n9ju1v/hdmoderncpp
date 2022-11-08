// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	// T a = 10; // �ᱹ �� ǥ��� �Դϴ�. 10 ���� T�� Ÿ�� �߷�
	auto a = 10; // T �ڸ��� auto �� �ִ� �� �Դϴ�.
				 // ��Ģ�� ���� �մϴ�.



	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	// T a1 = n; �Դϴ�. ��, "��Ģ 1"�Դϴ�.
	//			=> �캯 ǥ������ ���� const, volatile, reference ����
	//			   �� auto ����
	auto a1 = n;  // int a1
	auto a2 = r;  // int a2 
	auto a3 = c;  // int a3
	auto a4 = cr; // int a4

	// T& a5 = n;  // ��Ģ 2. �캯�� ���� reference �� ������ auto Ÿ�԰���
	auto& a5 = n;  // auto : int		a5 : int&
	auto& a6 = r;  // auto : int		a6 : int&
	auto& a7 = c;  // auto : const int  a7 : const int&
	auto& a8 = cr; // auto : const int  a8 : const int&

	// ��Ģ 3. forwarding reference
	auto&& a9 = 10; // �߿�! ������ ����
}


