// 일반 함수 : 실행시간에만 실행될수 있습니다.
int add1(int a, int b) { return a + b; }

// constexpr 함수
// => 실행시간에 실행될수도 있고, 
// => 컴파일 시간에 실행될수도 있습니다.
constexpr int add2(int a, int b) { return a + b; }

// consteval 함수 (C++20)
// => 컴파일 시간에만 실행될수 있습니다.
consteval int add3(int a, int b) { return a + b; }

int main()
{
	int x = 1, y = 2;

	add3(1, 2); // ok. 컴파일 시간에 실행 가능
	add3(x, y); // error
}