// 1_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
//-------------------------------
void f1(int  arg) {}
void f2(Point pt) {}

int main()
{
	// f1�� 3�� ������ �ʹ�.
	// ��� 1. ������ ���� ����
	int n = 3;
	f1(n);





//	Point pt(1, 2); 
//	std::cout << "-------" << std::endl;
}





