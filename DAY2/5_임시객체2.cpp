// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt(1, 2);
	
	// �ӽð�ü Ư¡ ����.
	// Ư¡ 1. �ӽð�ü�� lvalue �� �ɼ� ����.(rvalue �̴�.)
	pt.x = 10;			// ok	
	Point(1, 2).x = 10;	// error. �ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����.
						// ������ ����� �ƴϴ�.
						
//	Point(1, 2).set(10, 20); // �̷����ؼ� �����Ҽ� �� �ִ�.


	// Ư¡ 2. �ӽð�ü�� �ּ� �����ڷ� �ּҸ� ���Ҽ� ����.
	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error.
							

	// Ư¡ 3. �ӽð�ü�� non-const reference �� ����ų�� ����.
	// ��, const reference �δ� ����ų�� �ִ�.
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error

	const Point& r3 = Point(1, 2);	// ok
			// �� ��� �ӽð�ü�� ������ r3�� �������� ����ǰ� �˴ϴ�.
			// life-time extension

	r3.x = 10; // ��, r3�� ����̹Ƿ� ������ �ȵ˴ϴ�.


	// C++11 ������ ����� ���� �ӽð�ü�� ����Ű�� �;����ϴ�
	Point&& r4 = Point(1, 2); // ���� �ֿ� ����.!
}





