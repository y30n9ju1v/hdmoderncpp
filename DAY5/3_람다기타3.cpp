// "3_람다기타3" => 3-1 로 변경하고
// "3_람다기타3" 다시 만드세요

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();

	// 람다표현식이 만든 "타입" 은
	// 1. 디폴트 생성자가 삭제되어 있습니다.
	// 2. 복사 생성자는 제공됩니다.

	decltype(f1) f2;		// error. 디폴트 생성자 필요
	decltype(f1) f3 = f1;	// ok.	  복사 생성자 사용!

	// 왜? 위와 같은 규칙을 만들었을까요 ? 이유를 생각해 보세요
	// => 캡쳐한 람다 표현식은 "멤버데이타" 가 있습니다.
	// => 디폴트 생성자가 있다면 초기화 되지 않은 멤버 데이타를 
	//    사용하게 되는 문제가 있습니다.

	// 캡쳐 하지 않은 람다는 디폴트 생성해도 문제없지 않나요 ??
	// => 그래서, C++20 부터 "캡쳐하지 않은 람다는 디폴트생성"됩니다.
}