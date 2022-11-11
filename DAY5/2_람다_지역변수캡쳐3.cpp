// 6_����_��������ĸ��1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// capture by reference ( ������ ĸ��)
	// => �Ʒ� �ڵ��� "v1=100" �� main ���������� �����ϰ� �˴ϴ�.
	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; }; 

	f1(0);
	std::cout << v1 << std::endl; // 100




	/*
	// ������ �������� ĸ���� ����
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a)  const
		{
			v1 = 100; // v1 �� int �� �ƴ� int& �Դϴ�.
					  // ��, ���ڵ�� v1�� ������ �ƴ϶�!
					  // v1 �� ����Ű�� ���� �����մϴ�.
					  // ����, operator() �� const �Լ��� ok!

			return a + v1 + v2
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);
	*/
}





