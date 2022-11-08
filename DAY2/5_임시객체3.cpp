// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
//================================================
// �ӽð�ü�� �Լ� ���� - 81 page

// �Լ� ���ڷ�
// const Point& : ���ڷ� ���޵� ��ü�� �б⸸ �ϰڴٴ� ��(in parameter)
// Point&       : ���ڷ� ���޵� ��ü�� �����ϰڴٴ� �ǵ�(out paremeter)
//										 �Ǵ� in/out parameter
void draw_point(const Point& pt) {}
void init_point(Point& pt) { pt.x = 0; }


int main()
{
//	Point pt(1, 2);
//	draw_point(pt);

	// �ٽ� 1. �Լ� ���ڷθ� ����� ��ü�� �ʿ� �ϸ�
	//        "�ӽð�ü" ���·� �����ϴ� ���� ����
	draw_point( Point(1, 2) );

	// �ٽ� 2. �Ʒ� �ڵ尡 �Ǵ°� ������ �ȵǴ°� ������ ������ ������
	draw_point(Point(1, 2)); // �Ǿ� �Ѵ�.
							 // �׷��� const & �� �ӽð�ü�� ������ �ִ�
	
	init_point(Point(1, 2)); // �ȵǴ� �� �������� �´�
							 // �׷��� non-const & �δ� �ӽð�ü��
							 // ������ ����
							 // error 


	std::cout << "-----" << std::endl;
}






