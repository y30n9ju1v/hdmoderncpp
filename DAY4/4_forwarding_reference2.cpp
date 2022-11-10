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
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
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

// github 에 있는
// 
// "4_forwarding_reference2.cpp"
// "4_forwarding_reference3.cpp"

// 복사해 주세요.