#include <iostream>
#include <vector>
#include <algorithm>


bool foo(int n) { return n % 3 == 0; }

struct IsDivide
{
	int value;	// 함수 객체는 멤버 데이타도 있고

	IsDivide(int n) : value(n) {} // 생성자도 있습니다.

	bool operator()(int n) const {	return n % value == 0;}
};
int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;

	IsDivide f(k);
	bool b = f(10); // 결국 "10 % k == 0" 을 조사하는 단항 함수
					// 즉, f는 k의 값을 캡쳐한 단항함수 입니다.

	// 주어진 구간에서 1번째 나오는 "k 의 배수" 를 찾고 싶다.!
	auto p2 = std::find_if(v.begin(), v.end(), f);

	std::cout << *p2 << std::endl; // 6

	// 임시객체형태로 전달
	auto p3 = std::find_if(v.begin(), v.end(), foo);	
								// => 단항 함수만 전달

	auto p4 = std::find_if(v.begin(), v.end(), IsDivide(k));
								// => 단항 함수 + 지역변수k 전달
}





