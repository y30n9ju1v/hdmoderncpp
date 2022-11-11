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
		// delete ptr �� ���� �ʰ�
		// ���ø� 2��° ���ڷ� ���� �Լ� ��ü�� ����մϴ�.
		Dx d;	
		d(ptr);	
	}
};
// free �� �����ϴ� �Լ� ��ü
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