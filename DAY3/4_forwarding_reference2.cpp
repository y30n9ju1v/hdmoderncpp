// 91 page
int main()
{
	int n = 10;


	int *p = &n;
	int* *pp = &p;	// ok. �����͸� ����Ű�� �����͸� �����
					//     �ֽ��ϴ�. ( ���� ������ )

	int& r = n;
//	int& &rr = r;	// error. reference �� ����Ű�� reference
					//		�� ���� �ڵ����� ����� �����ϴ�.

	// Ÿ�� �߷� �������� �߻��Ǵ� reference �浹�� ������ �ƴմϴ�.
	// "reference collapsing" �̶�� ��Ģ�� ����˴ϴ�.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing
	LREF& r3 = n;	// int&  &		=> int&
	RREF& r4 = n;	// int&& &		=> int&
	LREF&& r5 = n;	// int&  &&		=> int&
	RREF&& r6 = 10;	// int&& &&		=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// �Ʒ� ó�� ����ߴٸ�  r�� Ÿ���� ?
				// "int& & r = a"
				// "int& r = a"
}

foo<int&>(n); 




