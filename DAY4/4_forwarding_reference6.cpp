#include <iostream>
#include <vector>

int main()
{
	std::vector<int>  v1 = { 0,0,0,0,0 };
	std::vector<bool> v2 = { 0,0,0,0,0 };

	auto a1 = v1[0];
	auto a2 = v2[0];

	// 핵심 : 아래 타입 출력 결과 예측해 보세요
	std::cout << typeid(a1).name() << std::endl;
	std::cout << typeid(a2).name() << std::endl;
}