// 1_�ʱ�ȭ9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "1 int" << std::endl;	}
	Point(int, int) { std::cout << "2 int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "3 initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	// Point(int) ������ ȣ��
	Point p2(1, 2);	// Point(int, int) ������ ȣ��

	Point p3( { 1,2 } ); // Point(initializer_list) ������ ȣ��

	Point p4{ 1,2 };// 1. Point(initializer_list) �� ������ ���
					// 2. 1�� ���ٸ� Point(int, int) ���

//	Point p5(1, 2, 3); // error. Point(int, int,int) �� ����

	Point p6{ 1, 2, 3 }; // ok.. Point(initializer_list) ���
	Point p7 = { 1,2,3 };// ok.. Point(initializer_list) ���

	// ��� : ������ ���ڷ� "initializer_list" �� ����ϸ�
	//       => �߰�ȣ �ʱ�ȭ�� ����ؼ� ���� ���޽� ��� ������ �ֽ��ϴ�.

	// C++11 ���� STL ���� �Ʒ� ó�� ��� ������ ����
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };
				// vector(std::initializer_list<T>) ������ ���

	// std::initializer_list<T> �� ������ Ÿ���Դϴ�.
	// call by value �� ����ϸ� �˴ϴ�.
}


