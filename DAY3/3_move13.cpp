#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// move ������ ����� �ʿ� ���� ���!

	// 1. ���ڷ� ���� ���� ���������� ����(retain) ���� �ʴ� ���
	//    move ������ʿ� �����ϴ�.
	// => �Ʒ� �Լ����� msg �� People �����ϴ� �ڿ��� �ƴմϴ�.
	//   ����, �б⸸ �մϴ�. move ��� ��� �ƴմϴ�.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}

	// 2. move �� ȿ���� ���� Ÿ���� move ��� ���� ������
	// => primitive type
	// => ���� �Ҵ� �ڿ��� ���� Ÿ�Ե�(Point, std::array ��)

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
	p.print_msg(std::move(s) ); // ���� �ƴ�.
								// move ȿ���� ����.
								// �������ϵ� �ƴ�!!

	p.set_data(arr);
}








