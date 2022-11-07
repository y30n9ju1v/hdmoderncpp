// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; // C++11 operator"" 으로 만든
								// 다양한 리터럴 접미사가 있습니다.

void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello"); // const char*
	foo("hello"s); // string operator""s("hello") 호출
			
	std::chrono::seconds s = 1h + 20min + 20s;
					// hours 객체 + minutes 객체 + seconds 객체

	std::cout << s.count() << std::endl; // 4820
}


