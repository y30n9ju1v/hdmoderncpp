// std::move()�Ұ�
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }
	// ���� ������ 
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}
	/*
	// �̵� ������(move constructor). rvalue�� ���� ���� ������ 
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}
	*/
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;		// c1 �� lvalue. ����
			
	Cat c3 = foo();		// �ӽð�ü rvalue. �̵�

	Cat c4 = static_cast<Cat&&>(c2);
						// c2�� ���ؼ��� ���簡 �ƴ� �̵��� �ش޶�� ��

	Cat c5 = std::move(c3); // �� ǥ�� �Լ��� ���� ���� ĳ������ ����
							// �մϴ�.

	// ���� : std::move ��ü�� �ڿ��� �̵��ϴ� �� �ƴմϴ�.
	// 1. ���� lvalue ��ü�� "rvalue�� ��ȯ" �ϴ� �۾��� �մϴ�
	// 2. Cat Ÿ�Ծȿ� move �����ڿ��� ���� �ڿ��� �̵� �˴ϴ�.


	
	// move �����ڰ� ���µ�. std::move() �� ����ߴٸ�
	// 1. move �����ڰ� �ִٸ� move ������ ȣ��. �ڿ��� �̵�!
	// 2. move �����ڰ� ���ٸ� copy ������ ȣ��. �ڿ��� ����!

	// ��, move �� �������� ���� Ÿ�Ե�, std::move() ��밡���մϴ�.
	// => ��, ���� ����� �����ϴ�.
	Cat c6 = std::move(c4);
}




