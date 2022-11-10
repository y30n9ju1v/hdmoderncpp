
struct Point
{
	int x, y;
	
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// �Ʒ� ������ �ǹ̸� ��Ȯ�� ������ ������
	Point pt = Point(1, 2);

	// C++98 : 1. Point(1,2) �� �ӽð�ü ���� - ������ ȣ���.
	//         2. �ӽð�ü�� pt �� ���� - ���� ������ ȣ��
	//			���� �����ڰ� private �� �ִٸ� ������ ����

	//			�׷���, C++ �����Ϸ����� ����ȭ �ؼ� ���� ������ ȣ���� ����
	//			���� 2�� �����ڸ� ȣ��(��, ��������ڰ� public�� �־�� ����)

	// C++11 : 1. Point(1,2) �� �ӽð�ü ���� - ������ ȣ���.
	//         2. �ӽð�ü�� pt �� �̵� - move ������ ȣ��
	//			  move �����ڰ� private �� �ִٸ� ������ ����

	//			�׷���, C++ �����Ϸ����� ����ȭ �ؼ� move ������ ȣ���� ����

	// C++17 : ���� ������ �� move ������ ȣ���� �����ϴ� ����ȭ��
	//			��� �����Ϸ��� ���Ѿ��ϴ� �����̵�.!!
	//			���� ���� 2�� �����ڸ� ȣ��
	Point pt = Point(1, 2); // ����2�� �����ڸ� ȣ��
	Point pt = std::move(Point(1, 2)); // ����ȭ�� ���� �ȵɼ� ����
									// �ӽð�ü ������ move ������
}