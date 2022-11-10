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


	// 인자가 2개 이상인 setter 에 move 를 지원하기!
	// => 직접 만들면 "4개" 의 함수가 필요 합니다.

	// 이경우는 "forwarding reference" 가 좋습니다.
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// setter 뿐 아니라, 생성자도 move 를 지원하려면
	// 위처럼 하세요
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}

	// move 지원 생성자 - forwarding reference
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
	// pair 에서 인자 2개인 생성자를 확인해봅시다.
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