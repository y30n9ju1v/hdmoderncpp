// 3_초기화4-1
#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // 사용자가 'a' 를 입력 했습니다.

	std::cout << n << std::endl; // 1. 97
								 // 2. 10
								 // 3. 0  => 답! 입력 실패!
								 // 4. -1

	// 입력 실패를 조사하는 방법 1.  fail 멤버 함수 사용
	if ( std::cin.fail() ) {}

	// 방법 2. cin 자체를 if 문에 넣을수 있습니다.
	// => 객체의 scalar test 라고 합니다.
	if (std::cin)
	{
		// 입력 성공한 경우.
	}
}


