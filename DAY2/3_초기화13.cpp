// 3_초기화13 - 초기화 0 복사 해오세요
#include <complex>
#include <vector>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	// => {} 초기화로 해결
	int n1 = { 10 };
	int n2{ 10 };
	int x[2] = { 1,2 };
	std::complex<double> c{ 1, 2 };


	// 2. 동적 할당한 배열을 초기화 할수 없다.
	// => {} 초기화 로 해결
	int* p = int[3]{1,2,3};


	// 3. STL 컨테이너 사용시 1,2,3,4 등으로 초기화 할수 없습니다.
	// => {} 초기화와 initializer_list 로 해결
	std::vector<int> v1 = { 1,2,3,4 };
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int n;		
	int x[3] = {0,0,0}; // C++11 부터 가능
public:
	Test() : n(0) {}
};



