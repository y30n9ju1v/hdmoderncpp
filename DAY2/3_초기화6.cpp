// 1_�ʱ�ȭ6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};
int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 }; // copy   initialization
	int n3;			// default initialization
	int n4{};		// value initialization	
					// => ����Ʈ ���� 0���� �ʱ�ȭ

	std::cout << n4 << std::endl; // 0

	Point pt{};		// ��� ����� 0����
					// ��, ����ڰ� �����ϴ� �����ڰ� ������
					// "= default" �� ���� 0����!

	std::cout << pt.x << std::endl;

	int arr[5] = {};
	std::cout << arr[3] << std::endl;
}


