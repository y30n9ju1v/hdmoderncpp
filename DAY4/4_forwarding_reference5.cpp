#include <vector>
#include <iostream>

// STL vector 를 생각해 봅시다.
// 아래 코드는 단순화 하기위해 "allocator 생략" 했습니다.
template<typename T> 
class vector
{
	T* buff;
public:
	vector(std::size_t sz, T value)
	{
		buff = new T[sz];
	}
	T& operator[](int idx) { return buff[idx]; }
};

// STL vector 는 bool 타입에 대해서 특수화 되어 있습니다.
template<>
class vector<bool>
{
	int* buff;
public:
	vector(std::size_t sz, bool value)
	{
		buff = new int[(sz / 32) + 1];  // 0~31 : int 1개
										// 32~63: int 2개로 관리
	}
	struct bit_proxy
	{
		int* buff;
		int idx;
	public:
		bit_proxy(int* p, int n) : buff(p), idx(n) {}

		operator bool()
		{
			std::cout << "v[] 가 우변에 있을때" << std::endl;
			return buff[idx];
		}
		bit_proxy& operator=(bool b)
		{
			std::cout << "v[] 가 좌변에 있을때" << std::endl;
			buff[idx] = b;
			return *this;
		}
	};
	bit_proxy operator[](int idx) { return bit_proxy(buff, idx); }
};
int main()
{
	vector<int>  v1(10, 0);
	vector<bool> v2(10, 0); 

	bool b = v2[0]; // bit_proxy임시객체.operator bool()
	v2[0]  = true;  // bit_proxy임시객체.operator=(true)

	
}