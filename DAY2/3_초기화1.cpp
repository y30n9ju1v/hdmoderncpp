// �ʱ�ȭ - 55 page
#include <iostream>

int x = 10;

class Test
{
	// C++11 ���� �Ʒ� ó�� �������Ÿ�� ���� �ʱ�ȭ �Ҽ� �ֽ��ϴ�.
	// => ���� ���̴µ�, ������ �˾� �μ���
	// => ���� "0" ���� ���ͷ� �ʱ�ȭ�� ����ϼ���. 
	// => "++x" ���� ǥ����� ������� ������.
	int value1 = 0;
	int value2 = ++x;
public:	
	Test() {}
	Test(int n) : value2(n) {}
};
// �� �ڵ�� ������ �ϸ� �Ʒ� ó�� ����˴ϴ�.
/*
class Test
{
	int value1; // = 0;  �̰��� �ִ� �ʱⰪ�� "��� �����ڿ� �ʱ�ȭ ����Ʈ��
				//		�Ű����� �˴ϴ�.
	int value2 = ++x;	// ��, value2�� ���� 2��° �����ڿ� �̹� �ʱ�ȭ�ڵ尡
						// �����Ƿ� 1��° �����ڿ��� �߰� �˴ϴ�.
public:
	Test()      : value1(0), value2(++x) {}
	Test(int n) : value1(0), value2(n) {}
};
*/

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // �����غ�����. ? 11
}