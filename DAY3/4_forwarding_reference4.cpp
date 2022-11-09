struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};



// ��� 1. call by value
// => lvalue, rvalue ��� ������ ������
// => ���纻�� �����ȴ�.
// void foo(Point pt) {}


// ��� 2. call by reference
// => ���纻�� �������� ������
// => lvalue �� ������ �ִ�, rvalue �� ������ ����.
// void foo(Point& pt) {}


// ��� 3. call by const lvalue reference
// => ���纻 ����,
// => lvalue, rvalue ��� �����ϴ�.
// => �׷���, const �Ӽ� �߰���. std::move(pt) ���� �۾��� �ȵ�. �б⸸ ����
// void foo(const Point& pt) {}

//========== C++98�� ���������!!=========================

// ��� 4. 2���� �Լ� - C++11 ����
// => ���纻 ����, const �� �߰� �ȵǰ�, lvalue/rvalue ��� ����
// void foo(Point&  pt) {}
// void foo(Point&& pt) {}


// ��� 5. forwarding reference ���
// => ���4�� 2�� �Լ��� �ϴ����� ����(����)�ϰ�
// => Point �� �ƴ϶� ��� Ÿ�Կ� �ʿ� �ϸ�
// => forwarding reference �� ����ϸ� �ڵ� �����Ҽ� �ִ�.

template<typename T> void foo(T&& pt) {}


int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}
