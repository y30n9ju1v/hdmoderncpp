// 3_람다기타3-3
#include <memory>
#include <set>

int main()
{
	// STL 의 많은 클래스가 템플릿 인자로 함수 객체를 요구 합니다.
	// 이때 함수 객체를 직접 만들지 말고,
	// 람다를 사용하고 싶으면

	// 아래 코드가 "effective modern C++" 에서 설명하는 코드입니다.
	auto deleter = [](void* p) { free(p); };

	std::unique_ptr<int, decltype(deleter)> up((int*)malloc(100),
													deleter);

	// 그런데, C++20 부터는
	// 1. 람다표현식이 평가되지 않은 표현식에 들어 갈수 있고
	// 2. 람다표현식이 만드는 타입에 디폴트 생성자가 있습니다.(캡쳐하지 않으면)


	std::unique_ptr<int, decltype([](void* p) { free(p); })> 
								up2((int*)malloc(100));
}