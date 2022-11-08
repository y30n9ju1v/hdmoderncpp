#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	// 아래 코드중 에러를 찾아 보세요.
//	goo(10);	// 안되는 게 좋습니다.
				// 컴파일 결과도 error 입니다.

	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error
								// "explicit vector(int)" 라는 의미

	hoo("hello");	// 되는게 좋습니다.
					// 컴파일 결과도 ok 입니다.

	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok
		// "string(const char*)" 가 explicit 가 아니라는 의미입니다.




}





