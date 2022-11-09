#include <iostream>
// 85 page
struct Base
{
	int value = 10; 
};
struct Derived : public Base
{
	int value = 20;
};
int main()
{
	Derived d;
	std::cout << d.value << std::endl;	// 20
	std::cout << static_cast<Base>(d).value << std::endl;	// 10 
	std::cout << static_cast<Base&>(d).value << std::endl;	// 10

	static_cast<Base>(d).value = 20;	// error. �ӽð�ü��
										//   lvalue �� �ɼ� ����.
	static_cast<Base&>(d).value = 20;	// ok

	// �� ĳ������ "�ӽð�ü�� ����" �ϴ� ǥ��� �Դϴ�.
}

