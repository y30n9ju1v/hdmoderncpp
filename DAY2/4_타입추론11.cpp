
int main()
{
	int x[3] = { 1,2,3 };

//	auto a = x[0];		// int
//	decltype(x[0]) d;	// int&


	// 배열과 타입 추론
	// 현재 x 타입 : int[3]
	auto a1 = x;	// 1. "int a1[3] = x" 로 추론. 그런데 에러!
					// 2. "int* a1 = x" 로 추론하면 에러 아님. 
					//    답은 2번

	auto& a2 = x;	// auto : int[3] 
					// a2   : int(&a2)[3] 으로 결정되는데.
					// "int(&a2)[3] = x" 는 에러가 아니다.
					// 배열을 가리키는 참조

	// 정리. auto로 배열을 가리킬때
	// 값 타입이면 : auto 가 포인터로 추론되고
	// 참조 타입이면 : auto 가 배열로 추론됩니다.

	decltype(x) d;	// int d[3];  초기값 없으므로 ok.  
}

