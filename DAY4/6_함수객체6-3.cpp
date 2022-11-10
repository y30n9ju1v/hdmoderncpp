
struct Point
{
	int x, y;
};

Point operator+(const Point& p1, const Point& p2)
{
	Point p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	return p3;
}

int main()
{
	Point p1 = { 0,0 };
	Point p2 = { 1,1 };

	operator+(p1, p2); // �Լ� �̸��� ���� ����ص� ������
	p1 + p2;		   // �̷��� �ص� �˴ϴ�.
	 
}

