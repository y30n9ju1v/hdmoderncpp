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
	// 방법 1. 2개의 setter 만들기
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }


	// 방법 2. forwarding reference 사용

	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
		name = n;
		name = std::move(n);
		name = std::forward<T>(n);
	}
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; // ""

}

