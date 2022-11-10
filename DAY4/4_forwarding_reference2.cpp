#include <iostream>
#include <string>
#include <vector>

// github �� �ִ� 
// "4_forwarding_reference2.cpp" "4_forwarding_reference3.cpp"
// ������ �ּ���.

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;
public:
	// move �� �����ϴ� setter ����� ��� 
	// ��� 1. 2���� setter �����
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }


	// ��� 2. forwarding reference ���

	template<typename T>
	void set_name(T&& n)
	{
		// ������ �´� ���� ?
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

