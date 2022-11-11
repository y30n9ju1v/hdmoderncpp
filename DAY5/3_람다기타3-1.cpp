#include <iostream>

template<typename T, 
	     typename Dx = std::default_delete<T> > class unique_ptr
{
	T* ptr;
public:
	unique_ptr() = default;
	explicit unique_ptr(T* p) : ptr(p) {}

	~unique_ptr()
	{
		// delete ptr 을 하지 않고
		// 템플릿 2번째 인자로 받은 함수 객체를 사용합니다.
		Dx d;	
		d(ptr);	
	}
};
// free 를 수행하는 함수 객체
struct Freer
{
	inline void operator()(void* p) const noexcept
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};

int main()
{
//	unique_ptr<int> up(new int);

	unique_ptr<int, Freer> up( (int*)malloc(40) );
}