#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };


	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// => 3번째 인자는 반드시 단항함수(인자가 한개) 이어야 합니다.
	auto p1 = std::find_if(v.begin(), v.end(), foo);


	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 1번째 나오는 "k 의 배수" 를 찾고 싶다.!

	auto p2 = std::find_if(v.begin(), v.end(), "단항함수 + k값");

}

// 일급 객체(first class object)
// => 함수 인자로 전달 가능한 객체
// => C/C++에서는 "함수"도 일급 객체이다.

// Closure(클로져)
// => 문맥에 속한 지역변수를 캡쳐할수 있는 일급객체

// 일반함수 : 일급객체이지만 클로져는 아닙니다.
// 함수객체 : 클로져입니다.!





