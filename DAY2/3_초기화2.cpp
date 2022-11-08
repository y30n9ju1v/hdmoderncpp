#include <complex>

int main()
{
	// C++98 시절은 변수의 종류에 따라 초기화 방법이 달랐습니다.
	int n1 = 10;
	int n2(10);		// C언어는 안되지만 C++은 가능합니다.
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);


	// C++11 부터는 모든 종류의 변수를 {} 로 초기화 가능합니다.
	// "일관된 초기화(uniform initialization)" 
	// => 흔히, 중괄호 초기화(brace init) 이라고도 합니다.
	int n1 = { 10 };
	int x[2] = { 1,2 };
	std::complex<double> c = { 1, 2 };

	// = 이 없어도 됩니다.
	int n1 { 10 };
	int x[2] { 1,2 };
	std::complex<double> c { 1, 2 };

	// 직접 초기화(direct initialization) : =이 없는 것
	// 복사 초기화(copy   initialization) : =이 있는 것

}












