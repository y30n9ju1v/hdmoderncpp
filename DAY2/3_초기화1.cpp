// 초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	// C++11 부터 아래 처럼 멤버데이타를 직접 초기화 할수 있습니다.
	// => 쉬워 보이는데, 원리를 알아 두세요
	// => 주의 "0" 같은 리터럴 초기화만 사용하세요. 
	// => "++x" 같은 표기법은 사용하지 마세요.
	int value1 = 0;
	int value2 = ++x;
public:	
	Test() {}
	Test(int n) : value2(n) {}
};
// 위 코드는 컴파일 하면 아래 처럼 변경됩니다.
/*
class Test
{
	int value1; // = 0;  이곳에 있는 초기값은 "모든 생성자에 초기화 리스트로
				//		옮겨지게 됩니다.
	int value2 = ++x;	// 단, value2의 경우는 2번째 생성자에 이미 초기화코드가
						// 있으므로 1번째 생성자에만 추가 됩니다.
public:
	Test()      : value1(0), value2(++x) {}
	Test(int n) : value1(0), value2(n) {}
};
*/

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 예측해보세요. ? 11
}