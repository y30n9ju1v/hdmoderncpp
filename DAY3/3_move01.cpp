#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// 이 순간 s1의 문자열을 s3가 깊은 복사.
	std::string s4 = std::move(s2);
							// s2의 문자열을 s4로 이동
							// s2 는 자원 없음

	std::cout << s1 << std::endl;// "hello"
	std::cout << s2 << std::endl;// ""


}

