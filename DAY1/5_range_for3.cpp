#include <iostream>
#include <vector>

// ����� ���� Ÿ���� ���ο� for ��(range-for) �� ��������
// begin()/end() �� ��� �Լ� �Ǵ� �Ϲ��Լ��� �����ϸ� �˴ϴ�.

struct Point3D
{
	int x, y, z;

//	int* begin() { return &x; }
//	int* end()   { return &z + 1; } // ������ ���� ��Ҹ�
									// ����Ű�� �ݺ���(�ּ�)
};
int* begin(Point3D& p) { return &(p.x); }
int* end(Point3D& p)   { return &(p.z) + 1; }


int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // �ɱ�� ? �ǰ��Ϸ��� �ʿ��� ���� ?
		std::cout << n << std::endl; 
	//=================
//	auto first = std::begin(p); // �� �����ؾ� �մϴ�
}















