// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열 : "\" 를 특수 문자로 해석
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw String : "\" 를 일반 문자열로 해석
	std::string s2 = R"(\\\\.\\pipe\\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
}