// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// �ƹ��ϵ� ���� ���� ���ڰ� ���� �����ڰ� �ʿ��ϸ�
	// => 2���� ������ �����ϴ�. 2�� ����ϼ���.
//	Point() {}			// 1. ���� ����ڰ� �����.
	Point() = default;	// 2. �����Ϸ����� ��û�Ѵ�.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




