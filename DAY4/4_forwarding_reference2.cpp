#include <iostream>
#include <string>
#include <vector>

// github 에 있는 
// "4_forwarding_reference2.cpp" "4_forwarding_reference3.cpp"
// 복사해 주세요.

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;
public:
	// move 를 지원하는 setter 만드는 방법 
	// => 현재 코드는 "방법1" 이 좋습니다.
	
	// 방법 1. 2개의 setter 만들기
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }

	// 방법 2. forwarding reference 사용
	template<typename T> void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
//		name = n;					// 항상 복사
//		name = std::move(n);		// 항상 move
		name = std::forward<T>(n);	// <== 정답
	}
};
int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;
	p.set_name(s1);				// copy 되어야 한다.
	p.set_name(std::move(s2));	// move 되어야 한다.

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; // ""

	//====================
	std::string s3 = "kim";
	const std::string s4 = "kim";

	// 아래 코드를 "방법1" 과 "방법2" 로 나누어 생각해 보세요
	// 방법 1. const std::string& 함수 한개로 모두 처리됩니다.
	// 방법 2. string&, const string& 버전을 각각 생성하게 됩니다.
	p.set_name(s3);
	p.set_name(s4);

	// 또한 방법 2. template 이라면 
	//			  아래처럼 string 이 아닌 경우도 함수 생성됩니다.
	//				단 "name = 3.4" 때문에 에러는 발생
	p.set_name(3.4); 

}

