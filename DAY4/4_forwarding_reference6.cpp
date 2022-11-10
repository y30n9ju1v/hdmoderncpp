#include <iostream>
#include <vector>

int main()
{
	std::vector<int>  v1 = { 0,0,0,0,0 };
	std::vector<bool> v2 = { 0,0,0,0,0 };

	auto a1 = v1[0]; // int a1
	auto a2 = v2[0]; // bool 이 아닌 bool 역할을 흉내낸 proxy 객체

	// 핵심 : 아래 타입 출력 결과 예측해 보세요
	// => auto 변수가 예상과 다른 타입일수도 있는 것 알아 두세요
	//    vector<bool> 의 operator [] 같이 proxy 기술을 사용하는
	//    경우가 종종 있습니다.
	std::cout << typeid(a1).name() << std::endl; // int
	std::cout << typeid(a2).name() << std::endl;


	for (auto& e : v1) // ok
	{	
	}

	for (auto& e : v2) // error.. 왜 ?? 에러일까요 ?
	{
	}
}




