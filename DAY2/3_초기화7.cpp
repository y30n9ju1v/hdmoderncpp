
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// �ٽ� : Point Ÿ���� ����Ʈ �����ڰ� �����ϴ�.

class Rect
{
	Point pt; // ?
public:
	// ����� �ڵ�	// �����Ϸ��� ������ �ڵ�
//	Rect() {}		// Rect() : pt() {}  
					// => Point�� ����Ʈ �����ڰ� �����Ƿ� ����

	// C++98 ���� �ذ�å : ��� ����Ÿ�� �����ڸ� ��������� 
	//					 ȣ���ϴ� �ڵ带 ����
	Rect() : pt(0, 0) {}
};

// C++11 �ذ�å
class Rect
{
	Point pt{ 0, 0 }; // ok
	Point pt(0, 0);   // ����!! ()�� �ȵ˴ϴ�.
public:
}

int main()
{
	Rect r1;
}

