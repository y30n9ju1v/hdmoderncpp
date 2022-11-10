// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::for_each(v.begin(), v.end(),
		[](int n) { std::cout << n << std::endl; });

	//===========================================
	// 람다표현식의 원리.
	// => 함수객체를 만드는 표기법 입니다.
	// => 흔히 "closure"를 만드는 표기법 이라고도 합니다.

	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int n) const
		{
			std::cout << n << std::endl;
		}
	};

	std::for_each(v.begin(), v.end(), CompilerGeneratedName() );

}





