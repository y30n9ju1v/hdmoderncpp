// chronometry1.cpp
#include <functional>


class Dialog 
{
public:
	void init(int a, double d) {} 
//  void init(Dialog* this, int a, double d) {} // ������ ��!
};

void foo(int a, double d) {}

int main()
{
	void(*f1)(int, double) = &foo;
//	void(*f2)(int, double) = &Dialog::init;

	// �ٽ� 1. ��� �Լ��� �ּҸ� �������� �Ʒ�ó�� �ؾ� �մϴ�.
	void(Dialog::*f2)(int, double) = &Dialog::init;

	// �ٽ� 2. ��� �Լ� �����ͷ� ��� �Լ� ȣ���ϱ�
//	f2(1, 3.4);  // error. ��ü�� �����ϴ�.

	Dialog dlg;
//	dlg.f2(1, 3.4); // error. f2 �� Dialog �� ��� �Լ��� �ƴմϴ�.
	
//	dlg.*f2(1, 3.4); // .* ������ ���(pointer to member)
					 // �׷���, �켱 ���� ����� ����.		
					 // .* ���� ( �� �켱������ �����ϴ�.

	(dlg.*f2)(1, 3.4); // ok. �� �ڵ尡 ��� �Լ� �����ͷ�
						// ��� �Լ� ȣ���ϴ� �ڵ��Դϴ�.

	// ����
	f1(1, 3.4);		   // �Ϲ� �Լ� ������ ���
	(dlg.*f2)(1, 3.4); // ��� �Լ� ������ ���

	// �ٽ� 4. C++17 std::invoke
	// => ��� ������ ȣ�� ������ ��ü�� ������ ������� ȣ���ϰ� ����
	std::invoke(f1, 1, 3.4);		// f1(1, 3.4)
	std::invoke(f2, dlg, 1, 3.4);	// (dlg.*f2)(1, 3.4)
}