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

	// ��� 2. ���ڷ� ������ "3"�� �ʿ� �ϸ� literal ���·� �����ϸ�ȴ�.
	f1(3);

	//================================
	// f2 �� 1, 2��� ���� ������ �ʹ�.
	// ��� 1. ��ü�� �����ؼ� ����
	Point pt(1, 2);

	f2(pt);

	// ��� 2. Point Ÿ���� literal ����
	f2( Point(1, 2) );	// ���� ���޿����θ� ����ϴ� ��ü ����
						// �ӽ� ��ü ��� �ϰ�(temporary)
						// "unnamed object"
						// "user define type �� literal" 
						// �̶�� �մϴ�.


//	Point pt(1, 2); 
//	std::cout << "-------" << std::endl;
}





