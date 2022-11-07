// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// 다음중 에러를 모두 고르세요
	int arr1[10];	// ok
	int arr2[n ];	// C89 : 배열의 크기는 컴파일 시간에 알아야 한다
					// C99 : 배열의 크기로 변수도 사용가능
					//      g++ 지원, VC++ 지원 안함

	int arr3[c1];	// ok. 컴파일 시간 상수
					//	컴파일 시간에 값을 알수 있다.

	int arr4[c2];	// error. 실행시간 상수, 
					// 컴파일 시간에는 값을 알수 없다.
}

void foo(const int cnt)
{
	int arr[cnt];	// error.  foo(n) 처럼 호출될수 있다.
					// 실행시간 상수 이다.!

}