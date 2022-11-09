#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// move 지원을 고려할 필요 없는 경우!

	// 1. 인자로 받은 것을 내부적으로 보관(retain) 하지 않는 경우
	//    move 고려할필요 없습니다.
	// => 아래 함수에서 msg 는 People 보관하는 자원이 아닙니다.
	//   단지, 읽기만 합니다. move 고려 대상 아닙니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// 2. move 의 효과가 없는 타입은 move 고려 하지 마세요
	// => primitive type
	// => 동적 할당 자원이 없는 타입들(Point, std::array 등)

	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.print_msg(std::move(s) ); // 에러 아님.
								// move 효과도 없음.
								// 성능저하도 아님!!

	p.set_data(arr);
}








