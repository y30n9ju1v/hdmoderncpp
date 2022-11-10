#include <iostream>
#include <string>
#include <vector>
#include <array>


class People
{
private:
	std::string name;
	std::string address;
public:


	// ���ڰ� 2�� �̻��� setter �� move �� �����ϱ�!
	// => ���� ����� "4��" �� �Լ��� �ʿ� �մϴ�.

	// �̰��� "forwarding reference" �� �����ϴ�.
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// setter �� �ƴ϶�, �����ڵ� move �� �����Ϸ���
	// ��ó�� �ϼ���
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}

	// move ���� ������ - forwarding reference
	template<typename T1, typename T2>
	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)),
		  addr(std::forward<T2>(a))
	{
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p(name, std::move(addr));

	p.set(name, addr);
	p.set(std::move(name), addr);
	p.set(name, std::move(addr));
	p.set(std::move(name), std::move(addr));
}