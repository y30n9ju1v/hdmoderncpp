#include <iostream>

template<typename T, typename Dx = std::default_delete<T> > class unique_ptr
{
	T* ptr;
public:
	unique_ptr() = default;
	explicit unique_ptr(T* p) : ptr(p) {}

	~unique_ptr()
	{
		Dx d;	
		d(ptr);	
	}
};
int main()
{
	unique_ptr<int> up(new int);
}