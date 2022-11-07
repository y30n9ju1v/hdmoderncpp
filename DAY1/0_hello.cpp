#include <iostream>

int main()
{
	std::cout << "hello, modern C++" << std::endl;

	int n1 = 10;
	
	// C++11 auto : 우변의 표현식으로 좌변의 타입을 결정해 달라
	auto n2 = 10;	// "int n2 = 10"
					// 실행시 성능저하는 없음.

	// C++11 decltype : () 안의 표현식으로 타입 결정
	//					// 초기값이 없어도 가능
	decltype(n2) n3;	// "int n3" 


	int x[3] = { 1,2,3 };

	decltype(x[0]) d1; // int& . 참조는 초기값 필요 하므로 error

	auto a1 = x[0];    // int

	auto a2 = x;	// a2 의 타입은 ? int* 
			
	decltype(x) d2; // int[3]

	auto&& a3 = 10;

}






// day1.zip 압축 풀고,
// 
// VC 사용하시는 분들은  VC 에서 열어 보세요

// 1. 버전 설정해야 합니다.
// => 프로젝트 메뉴/속성 메뉴 선택
// => 빌드 확인 : Ctrl + F5 

// 2. 소스 파일을 빌드에서 추가/제외 하는 방법 

// 수업 : 50분 수업 10분 휴식
// 점심 : 11:50 ~ 13:00