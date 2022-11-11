// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 
	
	// 람다의 지역변수 캡쳐의 원리
	class CompilerGeneratedName
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a) const 
		{
			v1 = 100; 
			return a + v1 + v2
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);

}





