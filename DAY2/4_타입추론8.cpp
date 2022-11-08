// decltype 규칙 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// 규칙 2. () 안에 "심볼의 이름과 연산자등을 포함한 표현식이 있을때"
	// => ()안의 표현식이 lvalue 가 될수 있으면 참조
	//    등호의 왼쪽에 올수 없으면(lvalue 아니면) 값 타입
	decltype(p)		d1; // int*,  규칙 1
	decltype(*p)	d2; // int&, *p = 0 가능.  초기값 없으므로 에러
	decltype(x[0])	d3; // int&, x[0] = 0 가능. 초기값 문제로 에러

	decltype(n) d;	// n = 0 이므로 lvalue 가 될수 있지만
					// 이름만 있으므로 규칙 1
					// int
	
	decltype((n)) dd; // int&,  규칙 2


	decltype(n + n) d4; // int,  n+n = 0 은 안됨. 

	n = 3;
	decltype(++n)   d5; // int&,  ++n = 10 은 에러가 아닙니다.
						
						
	decltype(n++)   d6; // int, n++ = 10 은 에러 입니다.


	int y[3] = { 1,2,3 };

	decltype(y[0]) k1; // int&
	auto k2 = y[0];	   // int, y[0] 은 참조타입인데..
						//     auto 는 우변의 참조를 버리고 결정하므로

}

