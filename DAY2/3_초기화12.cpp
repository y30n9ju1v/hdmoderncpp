// 3_�ʱ�ȭ12
#include <iostream>
#include <array> // C++11 array �����̳�

// C++11 array ������ ������ ���ô�.
template<typename T, std::size_t sz>
struct array
{
	T buff[sz];

	// array �� aggregate Ÿ���̾�� �մϴ�.
	// "������", "���� ������", "�̵� ������" ��� ����� �ȵ˴ϴ�.
	// 
//	array() {}
//	array(const array&) {} // ���� �����ڵ� "������"�� ���� �Դϴ�.
};

int main()
{
	// std::array �� aggregate Ÿ���̱⶧���� �Ʒ� ó�� ��밡���մϴ�
	array<int, 5> arr = { 1,2,3,4,5 };


}