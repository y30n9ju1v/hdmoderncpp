
// 6_forwarding_reference1 - ���� ���� �߿�!!
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);  // ok
f1(10); // error

// �Լ� ������ �ǹ�
// int&  : int Ÿ���� lvalue �� �ްڴٴ� ��
// int&& : int Ÿ���� rvalue �� �ްڴٴ� ��

// T& : ���� Ÿ���� lvalue �� �ްڴٴ� ��

// T&& : �ٽ�!!!


template<typename T> void f3(T& a)
{
}
int main()
{
	int n = 0;

	// 1. ����ڰ� Ÿ���� ���������� �����Ҷ�
	f3<int>(n );	// T = int		T& = int&		f3(int& a);
	f3<int&>(n );	// T = int&		T& = int& &		f3(int& a);
	f3<int&&>(n );	// T = int&&	T& = int&& &	f3(int& a);

	f3<int&&>(0);	// error. f3(int& )���� �����Ǿ��µ�
					// �ش� �Լ��� rvalue �� ���� �Ƿ�

	// 2. ����ڰ� Ÿ���� �������� ������ �����Ϸ��� 
	//    �Լ� ���ڸ� ���� �Լ��� �����ϱ����� T�� Ÿ���� �����մϴ�.
	f3(0);	// T �� int, int&, int&& �� � ������ �����ؼ�
			// 0�� �޴� �Լ��� ����� �����ϴ�.
			// ����!!

	f3(n);	// T = int �� ����. ���� �Լ��� "f3(int&)"
}


//==============================================



template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 0;

	// 1. Ÿ���� ���� �����ϴ� ���. �Ʒ� ? ä�� ������
	f4<int>(0);		// T=int	T&&=int&&		f4(int&& a)
	f4<int&>(n);	// T=int&	T&&=int&  &&	f4(int&  a)
	f4<int&&>(0);	// T=int&&	T&&=int&& &&	f4(int&& a)


	// 2. Ÿ�����ڸ� �����ϴ� ���

	f4(n);	// 1. n �� int Ÿ���̴�. T=int �� ��������!!
			// => ������ �Լ��� f4(int&& a) �̹Ƿ� "f4(n)" �� ����!!
				  
			// 2. n �� int Ÿ��������, T=int& �� �����ϸ� 
			// => f4(int&) �� �ǹǷ� "f4(n)" �� ������ �ƴϴ�.
			// => T=int& �� ��������!! => ����!!!!

	f4(0);	// T=int �Ǵ� int&& �� �����ϸ� �Ǵµ�.
			// ǥ�ؿ����� "T=int"�� ����
			// ������ �Լ��� "f4(int&&)"
}

// T&& : ���� Ÿ���� lvalue �� rvalue �� ��� ������ �ִ�.
//       "������ �ִ�" �� "������ �ִ� �Լ��� �����Ҽ� �ִ�" �� �ǹ�
// 
// Ư¡ : ������ �Լ��� ��� "call by reference" �Դϴ�.!!

// ��, ��� ��ü�� ���纻 ���� �ްڴٴ� ��!!

// �Ʒ� �ּ� �ݵ�� �ܿ켼��..!!
// �Լ� ���ڷ� 
// lvalue(n) �� ������ : T=int&    T&&=int& &&  �����Լ� f4(int&)
// rvalue(0) �� ������ : T=int     T&&=int&&    �����Լ� f4(int&&)

// �̸�
// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference

// T&&   : rvalue reference �� �ƴմϴ�.
//         "forwarding reference" �� ���� ��Ī
//		   "universal reference" ����� �մϴ�.(effective-C++)

