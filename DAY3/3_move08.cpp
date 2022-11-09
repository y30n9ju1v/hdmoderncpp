#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.
// ��Ģ1. ����ڰ� ����迭�� move �迭 �Լ��� ��� �������� ������
// => �����Ϸ��� ��� �����Ѵ�.
// => ���� �迭������ "��� ����� ����" ���ְ�
// => �̵� �迭������ "��� ����� �̵�" ���ش�.

// ��Ģ 2. ����ڰ� ���� �迭�� �����ϸ�
// => �����Ϸ��� move �迭�� �ڵ��������� �ʴ´�.
// => std::move() ���� ����ڰ� ���� ����迭 �Լ� ȣ��.

// => "=default" �� ����ϸ� �����Ϸ����� move �迭 �Լ��� �����޶��
//    ��û�Ҽ� �ִ�.

// ��Ģ 3. ����ڰ� move �迭�� ������ ���
// => �����Ϸ��� ���� �迭(������, ���� ����)�� ����("=delete") �մϴ�.
// => ���� �����ڰ� �ʿ��� �ڵ�� ��� ����!

// => ���� �����ڸ� ���� ����ų� �Ǵ� "=default"�� ��û�Ҽ��� �ֽ��ϴ�.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}


//	Object(const Object& obj) : name(obj.name) {std::cout << "user define copy" << std::endl;}
//	Object(Object&& obj) = default;
//	Object& operator=(const Object&) = default;
//	Object& operator=(Object&&) = default;

	// move �����ڸ� ������ ���
	Object(Object&& obj) : name(std::move(obj.name)) {}
};

int main() 
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;
}