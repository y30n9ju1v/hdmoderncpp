// 5_�ӽð�ü1-1

// 1_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// ��ü�� ����� 2���� ���
//	Point pt(1, 2); // named object
					// �̸��� �����Ƿ� ���� ���忡�� ��밡��
					// ���� : �ڽ��� ������ ���� ��.

//	Point(1, 2);	// unnamed object
					// temporary (�ӽð�ü) ��� �մϴ�.
					// ���� : �ڽ��� ������ "������ ��"

	// �Ʒ� �ڵ� ��� ������ ������.
	Point(1, 2), std::cout << "X" << std::endl; 

	std::cout << "-------" << std::endl;
}





