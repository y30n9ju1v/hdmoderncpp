// 7_�����ڻ��1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// �����ڴ� �⺻������ ��ӵ��� �ʽ��ϴ�.

	// C++11 ���ʹ� �Ʒ� ó�� ����ϸ� �����ڸ� ��� ������ �ֽ��ϴ�.
	using Base::Base; // "Ŭ�����̸�::����Լ��̸�"

	// �� ������ ���� ������ �Ʒ�ó�� ���� ����߽��ϴ�.
//	Derived()	   : Base() {}
//	Derived(int n) : Base(n) {}
};

int main()
{
	// �Ʒ� 2���� ������ ������
	Derived d1;
	Derived d2(5);
}
