#include <iostream>
#include <string>
#include <vector>

// �� move�� �߿��Ѱ� ? - 101 page �Ʒ� �ֽ��ϴ�.

template<typename T>
void Swap(T& a, T& b)
{
	// ���� ���翡 ���� swap 
	// ������ ���� �ʽ��ϴ�.
//	T tmp = a;
//	a = b;
//	b = tmp;

	// �ڿ� �̵��� ���� swap
	// �� �ڵ庸�� �����ϴ�.
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move �� �߿�� �ϴ� ����
// => swap, ���� ����� �Ϻ� �˰��� �ۼ��� ���簡 �ƴ� move �� ����ϸ�
//    ������ ���˴ϴ�.

// move ���� �˾ƾ� �ϴ� ��
// 1. swap ���� �˰��� ���鶧 std::move �� ������ڴ� ��!
// 
// 2. ����ڰ� ����� Ŭ������ move �� �����Ϸ��� ��� �ؾ� �ϴ°� ?
People p1("kim", 20);
People p2 = std::move(p1);	// move ȿ���� ������ People �� 
							// ��� ������ �ϴ°� ?


