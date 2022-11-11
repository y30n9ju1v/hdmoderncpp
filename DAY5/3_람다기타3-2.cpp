#include <iostream>

template<typename T,
	typename Dx = std::default_delete<T> > class unique_ptr
{
	T* ptr;
	Dx del;
public:
	unique_ptr() = default;
	explicit unique_ptr(T* p, Dx d = Dx()) : ptr(p), del(d) {}

	~unique_ptr()
	{
//		Dx del;	// 이렇게 하면 Dx 타입에 디폴트 생성자가 필요 합니다.
		del(ptr);
	}
};

int main()
{
	// 람다 표현식을 사용하면 함수 객체를 만들수 있다.!!

	// 도전 1. error
	// => 람다 표현식의 최종 결과는 "타입"이 아닌 "객체(임시객체)"
	// => 템플릿 인자는 "타입"을 전달해야 한다.
//	unique_ptr<int, [](void* p) { free(p); }  > up((int*)malloc(40));


	// 도전 2. error
	// => 람다표현식은 "평가되지 않은 표현식"에 놓일수 없다.!!
	// => decltype(), noexcept(), sizeof(), typeid() 의 ()안에
	//    넣을수 없다.
//	unique_ptr<int, decltype( [](void* p) { free(p); } ) > up((int*)malloc(40));


	// 도전 3. error
	// => decltype(deleter) 는 문제가 없다!!
	// => 그런데, 람다표현식이 만드는 타입은 디폴트 생성자가 없다.
	//    
	auto deleter = [](void* p) { free(p); };

	unique_ptr<int, decltype(deleter) > up((int*)malloc(40),
												deleter);
}










// free 를 수행하는 함수 객체
struct Freer
{
	inline void operator()(void* p) const noexcept
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};