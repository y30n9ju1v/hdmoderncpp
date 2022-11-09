#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	// ��� 1. call by value
	// => ���纻 ��ü ����, ���� �ڵ�
	//void set_name(std::string n) { name = n; }


	// ��� 2. call by const reference
	// => C++98 �������� �ּ��� �ڵ�
	// => C++11 ���Ŀ��� move�� ���� ���� ���ϴ� setter!!
//	void set_name(const std::string& n) { name = n; } // �׻� �������
//	void set_name(const std::string& n) { name = std::move(n); }
									// => n�� ��� ���� �̹Ƿ� 
									//    ���ڵ嵵 �׻� ���� �Դϴ�.


	// ��� 3. 2���� setter
	// => C++11 ���� setter �� ���鶧 move �� �����Ϸ���
	//    �����̸��� ��� �Լ��� 2�� �����ؾ� �մϴ�.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1 �ڿ� �����϶�� ��. s1 �� ��� �ڿ� ����
	p.set_name(std::move(s2));	// s2 �ڿ� �̵��� ����.!  s2 �� �ڿ� ����.

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

	//=========================
	std::vector<std::string> v;

	v.push_back(s1);			// s1�� �ڿ��� �����ؼ� v�� �߰�
	v.push_back(std::move(s1)); // s1�� �ڿ��� �̵�
}








