#include <vector>
#include <iostream>

// STL vector �� ������ ���ô�.
// �Ʒ� �ڵ�� �ܼ�ȭ �ϱ����� "allocator ����" �߽��ϴ�.
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

// STL vector �� bool Ÿ�Կ� ���ؼ� Ư��ȭ �Ǿ� �ֽ��ϴ�.
template<>
class vector<bool>
{
	int* buff;
public:
	vector(std::size_t sz, bool value)
	{
		buff = new int[(sz / 32) + 1];  // 0~31 : int 1��
										// 32~63: int 2���� ����
	}
	struct bit_proxy
	{
		int* buff;
		int idx;
	public:
		bit_proxy(int* p, int n) : buff(p), idx(n) {}

		operator bool()
		{
			std::cout << "v[] �� �캯�� ������" << std::endl;
			return buff[idx];
		}
		bit_proxy& operator=(bool b)
		{
			std::cout << "v[] �� �º��� ������" << std::endl;
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

	bool b = v2[0]; // bit_proxy�ӽð�ü.operator bool()
	v2[0]  = true;  // bit_proxy�ӽð�ü.operator=(true)

	
}