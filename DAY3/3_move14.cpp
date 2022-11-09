#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 핵심 : 인자가 2개인 setter 의 move 지원
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}

	void set(std::string&& n,std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}
	// 생성자도 마찬가지 입니다. 아래 처럼 한개 하면 안되고 4개 해야 합니다.
	People(const std::string& n, const std::string& a)
		: name(n), address(a) {}

	// 즉, 
	// 인자개 2개인 setter(생성자) : 4개의 함수
	// 인자개 3개인 setter(생성자) : 8개의 함수
	// 인자개 4개인 setter(생성자) : 16개의 함수

	// 해결책 : forwarding reference로 !!!

};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








