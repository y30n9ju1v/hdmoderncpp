#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;
public:
	Point(int a, int b) {}

	Point() {}			
//	Point() = default;	
};

int main()
{
	Point p1{}; // ���� ���� value initailization ����
				// ��� ����� 0���� �ʱ�ȭ
				// => ��, ����ڰ� ������ ������ �������� �ʴ� ��츸
				//	  ��, "= default"

	std::cout << p1.x << std::endl; // ok
}



