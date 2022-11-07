// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열 : "\" 를 특수 문자로 해석
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : "\" 를 일반 문자열로 해석
	// => 정규 표현식, 파일 경로 등 "\" 가 많이 사용될때를 위해서!
	// 문자열 시작 : "(
	//       종료 : )"
	std::string s2 = R"(\\\\.\\pipe\\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// 1. 문자열 안에 " 를 표기하고 싶다.
	// => 그냥 사용하면 됩니다.
	s2 = R"(pi"p'e)";

	// 2. 문자열 안에 )" 를 표기 하고 싶다면
	// => 문자열의 시작과 종료하는 기호를 바꿀수 있습니다.
	// 시작 : "***(  로 변경
	// 종료 : )***"  로 변경
	s2 = R"***(pip)"e)***";

	std::cout << s2 << std::endl;
}