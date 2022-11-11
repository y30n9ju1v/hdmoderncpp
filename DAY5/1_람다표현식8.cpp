int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										    a   = std::move(b); 
										    b   = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// 아래 코드는 되는게 좋을까요 ? 안되는게 좋을까요 ?
	swap(n, d); // error 가 발생하는 것이 좋습니다.
				// 그런데, 에러는 아닙니다.

	// swap 같은 것을 만들때는 2개의 인자가 "같은 타입" 이어야 한다는
	// 조건이 있으면 좋습니다.

	// 그래서 "C++20" 에서 template lambda 를 만들었습니다
	// C++14 : generic  lambda. 인자로 auto
	// C++20 : template lambda. 인자로 template

	auto swap2 = []<typename T>(T& a, T& b) { auto tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };

}