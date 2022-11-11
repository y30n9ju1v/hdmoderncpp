// 143 
#include <functional>

int main()
{
	// 람다표현식을 담는 방법
	// 1. auto 변수에 담기
	auto f1 = [](int a, int b) { return a + b; };

	// 2. 함수 포인터
	int(*f2)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{ operator()()}; xxx();

	// 3. std::function 에도 담을수 있습니다.
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	// 이제 f1, f2, f3 는 일반 함수 처럼 사용가능합니다.
	f1(1, 2);
	f2(1, 2);
	f3(1, 2);

	// 차이점 : auto 변수는 다른 람다를 담을수 없습니다.
	f1 = [](int a, int b) { return a + b; }; // error

	// f2, f3 는 컴파일러가 생성한 람다 타입이 아닌
	// 함수 포인터, std::function 타입의 변수이므로 변경가능합니다
	f2 = [](int a, int b) { return a + b; }; // ok
	f3 = [](int a, int b) { return a + b; }; // ok

	f1(1, 2); // 인라인 치환 됩니다.
	f2(1, 2); // 인라인 치환 안됩니다. 
			  // 인라인 함수 라도 함수 포인터에 담으면 치환될수 없다.
	f3(1, 2); // 치환 안됨
}