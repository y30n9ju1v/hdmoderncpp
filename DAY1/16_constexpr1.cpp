// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// ������ ������ ��� ������
	int arr1[10];	// ok
	int arr2[n ];	// C89 : �迭�� ũ��� ������ �ð��� �˾ƾ� �Ѵ�
					// C99 : �迭�� ũ��� ������ ��밡��
					//      g++ ����, VC++ ���� ����

	int arr3[c1];	// ok. ������ �ð� ���
					//	������ �ð��� ���� �˼� �ִ�.

	int arr4[c2];	// error. ����ð� ���, 
					// ������ �ð����� ���� �˼� ����.
}

void foo(const int cnt)
{
	int arr[cnt];	// error.  foo(n) ó�� ȣ��ɼ� �ִ�.
					// ����ð� ��� �̴�.!

}