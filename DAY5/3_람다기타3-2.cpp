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
//		Dx del;	// �̷��� �ϸ� Dx Ÿ�Կ� ����Ʈ �����ڰ� �ʿ� �մϴ�.
		del(ptr);
	}
};

int main()
{
	// ���� ǥ������ ����ϸ� �Լ� ��ü�� ����� �ִ�.!!

	// ���� 1. error
	// => ���� ǥ������ ���� ����� "Ÿ��"�� �ƴ� "��ü(�ӽð�ü)"
	// => ���ø� ���ڴ� "Ÿ��"�� �����ؾ� �Ѵ�.
//	unique_ptr<int, [](void* p) { free(p); }  > up((int*)malloc(40));


	// ���� 2. error
	// => ����ǥ������ "�򰡵��� ���� ǥ����"�� ���ϼ� ����.!!
	// => decltype(), noexcept(), sizeof(), typeid() �� ()�ȿ�
	//    ������ ����.
//	unique_ptr<int, decltype( [](void* p) { free(p); } ) > up((int*)malloc(40));


	// ���� 3. error
	// => decltype(deleter) �� ������ ����!!
	// => �׷���, ����ǥ������ ����� Ÿ���� ����Ʈ �����ڰ� ����.
	//    
	auto deleter = [](void* p) { free(p); };

	unique_ptr<int, decltype(deleter) > up((int*)malloc(40),
												deleter);
}










// free �� �����ϴ� �Լ� ��ü
struct Freer
{
	inline void operator()(void* p) const noexcept
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};