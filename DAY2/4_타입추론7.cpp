// decltype 타입 추론 - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// 참고!
	auto a = r; // int a = r;
				// auto 는 우변의 참조를 버리고 결정

	// 규칙 1. () 안에 심볼의 이름만 있는 경우
	// => 심볼의 선언을 보고 동일한 타입으로 결정
	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;			초기값 없으므로 error
	decltype(c) d3; // const int d3;	초기값 없으므로 error
	decltype(p) d4; // int* d4;
}