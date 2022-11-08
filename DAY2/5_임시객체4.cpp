// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// �ӽð�ü�� �Լ� ��ȯ�� -  82 page

/*
void f1(Point  pt) {}	// call by value : ���纻 ��ü ����
void f2(Point& pt) {}	// call by reference : ���纻 ���� �ȵ�.

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//=====================================================





Point pt(1, 2);

Point foo()  // return by value
{			 // �ӽð�ü�� �����ؼ� ��ȯ.
	return pt; 
}
Point& goo() // return by reference
{
	return pt; // �ӽð�ü�� �ƴ� pt �� ���� ��ȯ
}


// ����!! ���������� ����� ���� ��ȯ�ϸ� �ȵ˴ϴ�.
// �ı����� ���� ��ü(��������, �Ǵ� ��� ����Ÿ��)�� ���� ��ȯ�ؾ� �մϴ�
Point& hoo()
{
	Point p(1, 2);
	return p; // ����. �׷���, ������ �ƴϰ�, ��� �Դϴ�.
}

int main()
{
	foo().x = 10; // error. ���Ͽ��ӽð�ü.x = 10 �̹Ƿ� ����
				  // �ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����.

	goo().x = 10; // ok. pt.x = 10 �� ����. 

// 	Point& ret = hoo();
//	hoo().x = 10; // �̷��Ե� ����ϸ� �ȵ˴ϴ�.(�������� ��ȯ�̶��)
}





