// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

void init_point(Point& pt)       
{
	// pt �� ����Ű�� ��ü�� ����
	pt.x = 10;
	pt.y = 10;
}

void draw_point(const Point& pt) 
{
	// pt �� ����Ű�� ��ü�� �б⸸
}

void move_ctor(Point&& pt)
{
	// C++11 ���ʹ� �ӽð�ü�� ���ڷ� �޾Ƽ� ���� �����Ҽ� �ְ� �Ǿ���.
	// => �� �ӽð�ü�� �����ؾ� �մϱ� ??? move �� ����� ����!
	pt.x = 10;
}


int main()
{
	Point pt(0, 0);

	// ��Ģ 1. non-const lvalue reference �� lvalue �� ����ų�� �ִ�.
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error


	// ��Ģ 2. const lvalue reference �� lvalue, rvalue �� ��� ����ų�� �ִ�.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok

	// �� ������ ��ó�� ���� �߳��� ?
	// => ARM å ���� ( C++ annoted reference manual )


	// C++11 �� ����鼭 "����� ���� rvalue �� ����Ű�� �;���"
	// ��Ģ 3. rvalue reference �� rvalue �� ����Ų��.
	
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok 


	// �׷�. const rvalue reference �� ��� �ǳ��� ?
	// => rvalue �� ����ų�� �ֽ��ϴ�.
	// => �׷���, ���� ������ �ʱ� ������ �߿������� �ʽ��ϴ�.
	const Point&& r7 = pt;			// error
	const Point&& r8 = Point(0, 0);	// ok 
}
