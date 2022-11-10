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
	//==================
	// pair ���� ���� 2���� �����ڸ� Ȯ���غ��ô�.
	std::pair<std::string, std::string> p1(name, std::move(addr));
}

/*
template <class _Other1, class _Other2,
	enable_if_t<conjunction_v<is_constructible<_Ty1, _Other1>, is_constructible<_Ty2, _Other2>>, int> = 0>
	constexpr explicit(!conjunction_v<is_convertible<_Other1, _Ty1>, is_convertible<_Other2, _Ty2>>)
	
	pair(_Other1&& _Val1, _Other2&& _Val2) noexcept(is_nothrow_constructible_v<_Ty1, _Other1>&& is_nothrow_constructible_v<_Ty2, _Other2>) // strengthened
	: first(_STD forward<_Other1>(_Val1)), second(_STD forward<_Other2>(_Val2)) {
}
*/