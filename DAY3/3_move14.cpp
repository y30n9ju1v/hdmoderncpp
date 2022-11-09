#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// �ٽ� : ���ڰ� 2���� setter �� move ����
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
	// �����ڵ� �������� �Դϴ�. �Ʒ� ó�� �Ѱ� �ϸ� �ȵǰ� 4�� �ؾ� �մϴ�.
	People(const std::string& n, const std::string& a)
		: name(n), address(a) {}

	// ��, 
	// ���ڰ� 2���� setter(������) : 4���� �Լ�
	// ���ڰ� 3���� setter(������) : 8���� �Լ�
	// ���ڰ� 4���� setter(������) : 16���� �Լ�

	// �ذ�å : forwarding reference�� !!!

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








