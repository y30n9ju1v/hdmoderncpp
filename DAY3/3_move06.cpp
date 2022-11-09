#include <iostream>

// rule of 5, 3

// Ŭ�����ȿ� ������ ����� �ְ�, �����ڿ��� �ڿ��� �Ҵ��ϸ�

// C++98 ���� : 3���� �Լ��� �ݵ�� ������ �մϴ�.
//			   "�Ҹ���", "���������", "���Կ�����"
//			   "Rule Of 3" ��� �� ����߽��ϴ�.

// C++11 ���� : �� ��Ģ�� �߰��� 2���� �Լ��� �� ����� ����
//				"move ������", "move ���Կ�����"
//				"Rule Of 5"

// Rule Of 0 : �ƹ��͵� �ȸ���� ���� �ּ��̴�!


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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}

	// ���� �����ڸ� ����� �Ǵ� Ÿ���� ��κ� ���Կ����ڵ�
	// ������ �մϴ�.
	Cat& operator=(const Cat& c)
	{
		if (&c == this) return *this;

		age = c.age;

		// �̸��� ���� ����
		delete[] name; // ����ϴ� �ڿ� ����
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}
	// ���� �����ڵ� "move ����"�� �����ؾ� �մϴ�.
	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;	
		delete[] name;
		name = c.name;	// move ������ ���� ������
		c.name = nullptr;// ���� ��ü �ڿ������� reset

		return *this;
	}


};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;	// ���� ������ ( �ʱ�ȭ, �����ϸ鼭 �ֱ�)
	c2 = c1;		// ���� ������ ( ����, ������ �ֱ�)
					// c2.operator=(c1) �� ȣ��
					// ����ڰ� ������ ������ �����Ϸ� ����
					// (���� ����!)

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




