// ��������� ����� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// ���� �������� ��Ȯ�� ����� ������ ���ô�.

	// 1. call by value
	// => ���ڸ� ������ ����� "Point pt = p2" �Դϴ�.
	// => �ٽ� ��������ڰ� ȣ��Ǵ� ���
	// => ���� �����ڰ� ������ ȣ��Ǵ� ���� �Դϴ�.
	// => ���� �����ڴ� call by value �� ����� �����ϴ�.
	// Point( Point pt ) {}

	// 2. call by reference
	// => ������ ������ �ƴ�. 
	// => lvalue �� ������ �ְ�, rvalue �� ������ ����.
	// => �� Ÿ������ ��ȯ�ϴ� �Լ��� ����� ������ ����.
	//    "Point ret = foo()" �� ����!!
	// Point(Point& pt) {}

	// ��� 3. const lvalue reference
	// => lvalue �� rvalue �� ��� �������ִ�.
	// => �����Ϸ��� �����ϴ� ���� �����ڰ� �� ���.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
int main()
{
	Point p1;		// 1�� ������
	Point p2(1, 2); // 2�� ������

	Point p3( p2 );	// ���� ������ ���			

	Point p4 = foo(); // Point p4( foo() );
}




