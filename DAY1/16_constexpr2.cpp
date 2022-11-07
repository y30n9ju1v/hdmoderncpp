// constexpr 은 3가지 형태 입니다.
// 1. constexpr 상수 - C++11
// 2. constexpr 함수 - C++11  !!
// 3. constexpr if  - C++17


// constexpr 함수
// => 인자 값을 컴파일 시간에 알고
//    함수 호출이 사용되는 표현식이 컴파일 시간에 값을 알아야 한다면
//    함수 실행을 컴파일 시간에 수행

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; // 컴파일 하면 "int arr1[120]"			
							// 즉, 함수의 실행을 컴파일 할때 수행

	int arr2[Factorial(n)];	// error. 
							// 인자값을 컴파일 할때 알수 없다.
						
	int s2 = Factorial(n);	// ok. 실행할때 함수 호출


	int s = Factorial(5);	// 컴파일시간에 할수도 있고 실행시간에 호출할수도
							// 있습니다. 
							// 컴파일러마다 다름
	const int s3 = Factorial(5); // 컴파일러마다 다름

	constexpr int s4 = Factorial(5); //반드시 컴파일 할때 해달라.

}