#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	// ����Ʈ ������
	// 1. ���� ��ü ����
	// �Ʒ� �ڵ�� ���� �޸𸮸� ��� �Ҵ� �ұ�� ? 2��
	// => new Point(1,2)
	// => new ������ü;
//	std::shared_ptr<Point> sp1(new Point(1,2));


	// C++ ǥ�� shared_ptr �� ����Ҷ���
	// "std::make_shared" �� ����� ���� �����ϴ�.(���±���)
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);

					// 1. sizeof(������ü) + sizeof(Point) �Ҵ�
					// 2. Point ������ ȣ��. 1,2 ����
					// 3. shared_ptr �� ���� ��ȯ

}







