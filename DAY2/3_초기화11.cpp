// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization

// aggregate Ÿ���̶� ?
// => �����ڰ� ��� {}�� �ʱ�ȭ ������ Ÿ��
// => ����ü, �迭, union 
// => �Ʒ� Point �� "Point()" �����ڰ� ������ aggregate �� �ƴմϴ�.
//    Point pt = {1,2} �ʱ�ȭ �ȵ˴ϴ�.

struct Point
{
	int x, y;

	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2
};

int main()
{
	Point p1;			// 1 �� ������
	Point p2 = { 1, 2 };// 2 �� ������
}