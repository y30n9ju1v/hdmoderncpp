// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// capture by reference ( 참조로 캡쳐)
	// => 아래 코드의 "v1=100" 은 main 지역변수를 변경하게 됩니다.
	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; }; 

	f1(0);
	std::cout << v1 << std::endl; // 100




	/*
	// 람다의 지역변수 캡쳐의 원리
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a)  const
		{
			v1 = 100; // v1 은 int 가 아닌 int& 입니다.
					  // 즉, 이코드는 v1의 변경이 아니라!
					  // v1 이 가리키는 곳을 변경합니다.
					  // 따라서, operator() 가 const 함수라도 ok!

			return a + v1 + v2
		}
	};

	auto f1 = CompilerGeneratedName(v1, v2);
	*/
}





