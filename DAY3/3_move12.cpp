#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// 방법 1. call by value
	// => 복사본 객체 생성, 나쁜 코드
	//void set_name(std::string n) { name = n; }


	// 방법 2. call by const reference
	// => C++98 시절에는 최선의 코드
	// => C++11 이후에는 move를 지원 하지 못하는 setter!!
//	void set_name(const std::string& n) { name = n; } // 항상 복사대입
//	void set_name(const std::string& n) { name = std::move(n); }
									// => n은 상수 참조 이므로 
									//    이코드도 항상 복사 입니다.


	// 방법 3. 2개의 setter
	// => C++11 이후 setter 를 만들때 move 를 지원하려면
	//    동일이름의 멤버 함수를 2개 제공해야 합니다.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1 자원 복사하라는 것. s1 은 계속 자원 보유
	p.set_name(std::move(s2));	// s2 자원 이동해 가라.!  s2 은 자원 없음.

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

	//=========================
	std::vector<std::string> v;

	v.push_back(s1);			// s1의 자원을 복사해서 v에 추가
	v.push_back(std::move(s1)); // s1의 자원을 이동
}








