// C++98 초기화의 문제점 - 54 page
#include <complex>
#include <vector>

int main()
{
	// C++98 시절. 
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);


	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = new int[3];

	p[0] = 10; // 대입입니다. 초기화 아닙니다.


	// 3. STL 컨테이너 사용시 1,2,3,4 등으로 초기화 할수 없습니다.
	std::vector<int> v1(4, 0); // 4개를 0으로
							// 4개를 1,2,3,4로 할수 없을까?

//	v1 = 1, 2, 3, 4; // boost 라이브러리가 만들었던 기술
					 // "operator,()" 재정의해서 만든기술
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int n;		// 초기화 리스트로 초기화 가능
	int x[3];	// 초기화 리스트로도 초기화 못함
public:
	Test() : n(0) {}
};



