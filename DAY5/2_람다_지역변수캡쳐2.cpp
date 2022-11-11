// 6_����_��������ĸ��1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;
	// �Ϲ� ����ǥ������ "operator()" �� ��� �Լ� �Դϴ�.
//	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 


	// mutable ���� ǥ������ "operator()" �� ��� ����Լ��� �ƴմϴ�
	auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };
	
	f1(100);


	/*
	// ������ �������� ĸ���� ����
	class CompilerGeneratedName
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) // const 
		{
			v1 = 100; // error
					  // ��, mutable ���� ǥ�����̶�� const ����Լ����ƴϹǷ�
						// ���� �ƴ�

			return a + v1 + v2
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);
	*/
}





