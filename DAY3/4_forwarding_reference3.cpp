
// 6_forwarding_reference1 - ���� ���� �߿�!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);  // ok
f1(10); // error

// �Լ� ������ �ǹ�
// int&  : int Ÿ���� lvalue �� �ްڴٴ� ��
// int&& : int Ÿ���� rvalue �� �ްڴٴ� ��

// T& : ?


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 0;

	// 1. ����ڰ� Ÿ���� ��������� �����Ҷ�
	f3<int>(? );	// T = ?	a = ?		f3(? a);
	f3<int&>(? );	// T = ?	a = ?		f3(? a);
	f3<int&&>(? );	// T = ?	a = ?		f3(? a);


}











template<typename T> void f4(T&& a)
{
}
