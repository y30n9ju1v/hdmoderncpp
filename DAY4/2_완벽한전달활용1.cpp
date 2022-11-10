// 8_�Ϻ�������Ȱ��
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	// 1. ��ü�� �����Ŀ� �ֱ�
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. �ӽð�ü�� ����ؼ� �ֱ�
//	v.push_back(Point(1, 2));

	// 3. {} �� �ʱ�ȭ ǥ������� ����
	// => 2�� ���� {1,2}�� ������ �ӽð�ü �����ϴ� ����
//	v.push_back({ 1,2 });


	// 4. �ٽ�!!!!!
	// => ��ü�� �������� ���� ��ü�� ����� ���� ������ ���ڸ� ��������!

	v.emplace_back(1, 2);
			// �� �Լ� �ȿ��� 
			// "new Point(1,2)" ó�� ��ü������
			// ���ۿ� ����
			
			// emplace_back �� �ڽ��� ���� ���� ��� ���ڸ�
			// Point �� �����ڷ� "�Ϻ��� ����" �ؾ� �մϴ�.



	std::cout << "-----" << std::endl;
}


