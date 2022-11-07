// 16_constexpr1-1
int main()
{
	int n = 10;

	// C++98 const
	const int c1 = 10; // ok. 컴파일 시간 상수도 되고
	const int c2 = n;  // ok. 실행시간 상수(변수로 초기화)도 가능

	// C++11 constexpr 
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error
}