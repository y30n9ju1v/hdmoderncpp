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
	// 2. 우변 객체의 파괴 시점
	//									1		2
	std::string s3 = s1;			// copy		{} 벗어 날때
	std::string s4 = std::move(s2);	// move		{} 벗어 날때
	std::string s5 = foo();			// move		문장의 끝

}


//		lvalue				xvalue				prvalue(pure rvalue)
//						    std::move()된객체		임시객체