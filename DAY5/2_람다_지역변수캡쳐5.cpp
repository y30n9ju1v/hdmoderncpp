// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// ��� ����Ÿ ĸ�� ?
		// auto f = [](int a) { return a + data; }; // error

		//auto f = [data](int a) { return a + data; }; // error
										// data �� ���������� �ƴ�

		// ��� ����Ÿ�� ���� �Ϸ��� this�� ĸ���ؾ� �մϴ�.
		auto f = [this](int a) { return a + data; }; // ok


		// �Ʒ� �ڵ�� "��� data" �� �����ұ�� ? ���纻�� �����ұ�� ?
		// => ��ü�� ���纻�� �ƴ� �ּ��� ���纻�̹Ƿ�
		// => "data=a" �� ���� ��� ����Ÿ�� �����Դϴ�.
		auto f2 = [this](int a) { data = a; };

		f2(33);
		std::cout << data << std::endl; // ?

		// �Ʒ� �ڵ尡 �ּҰ� �ƴ� ��ü�� ���纻�� ĸ��
		// => C++17 ���� ����
		auto f3 = [*this](int a) mutable { data = a; };
	}
};

int main()
{
	Test t;
	t.foo(); 
}


