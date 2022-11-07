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
	int s = Factorial(5);

	int arr1[Factorial(5)]; 

	int arr2[Factorial(n)]; 
						
	int s2 = Factorial(n); 
}