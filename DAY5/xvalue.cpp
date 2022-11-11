// xvalue
#include <string>

std::string foo()
{
	std::string s = "aaa";
	return s;
}

int main()
{
	std::string s1 = "bbb";
	std::string s2 = "ccc";

	// 아래 3줄의 차이점을 생각해 봅시다.
	// 1. copy ? move 관점
	// 2. 객체의 파괴 시점
	//									1			2
	std::string s3 = s1;			//
	std::string s4 = std::move(s2);	//
	std::string s5 = foo();			//
}